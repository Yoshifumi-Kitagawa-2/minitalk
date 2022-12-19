/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:56:11 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/19 19:51:07 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"
#include <stdio.h>

//信号ハンドラー内での変数アクセスを原子的に行うことができるという点が特徴。原子的アクセスとは、複数のスレッドから同時にアクセスされることを防ぐことを意味する。
volatile sig_atomic_t g_atomic_data = 0;

void ft_put_error_exit()
{
    ft_putstr_fd("Error Occured\n", 1);
    exit(EXIT_FAILURE);
}

int ft_change_binary(size_t n)
{
    if (n == 0)
        return (1);
    else if (n == 1)
        return (2);
    else
        return (2 * ft_change_binary(n - 1));
}

static int nbr_to_str(uint8_t nbr)
{
    static  char    str[MAX_SIZE];
    static  size_t  i = 0;

    str[i] = nbr;
    if (nbr == EOT)
    {
        str[i] = '\0';
        i = 0;
        ft_putstr_fd(str,1);
        return(EOT);
    }
    else if (i == MAX_SIZE -1)
    {
        str[++i] = '\0';
        i = 0;
        ft_putstr_fd(str, 1);
    }
    else
        i++;
    return(0);
}

static void signal_handler(int signal, siginfo_t *info, void *context)
{
    static uint8_t  nbr = 0;
    static uint8_t  cnt = 0;
    (void)context;
    if (signal == ONEBIT)
        nbr += ft_change_binary(cnt);
    cnt++;
    if (cnt == 8)
    {
        cnt = 0;
        nbr = nbr_to_str(nbr);
        if (nbr == EOT)
        {
            kill(info->si_pid, CMPSIG);
            return ;
        }
    }
    kill(info->si_pid, ACKSIG);
}

int main(void)
{
    struct sigaction sa; //sigactio構造体を宣言。
    sigemptyset(&sa.sa_mask); //sa_maskを空に。
    //sa_maskにSIGUSR1/2を追加
    if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 || sigaddset(&sa.sa_mask, SIGUSR2) == -1)
        ft_put_error_exit();
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &signal_handler;
    //sigaction関数を使用することで、SIGINT信号を受け取ったときにsigint_handler関数が実行されるようになる
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        ft_put_error_exit();
    ft_putstr_fd("PID:",1);
    ft_putnbr_fd(getpid(), 1);
    while(1)
        pause();
    return(0);
}