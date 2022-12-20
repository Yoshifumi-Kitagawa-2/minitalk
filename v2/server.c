/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:23:11 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/20 15:00:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_change_binary(size_t n)
{
    if (n == 0)
        return (1);
    else if (n == 1)
        return (2);
    else
        return (2 * ft_change_binary(n - 1));
}

int nbr_to_str(int8_t nbr)
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
    static volatile sig_atomic_t  nbr = 0;
    static volatile sig_atomic_t  cnt = 0;
    static volatile sig_atomic_t  pid = 0;
    (void)context;
    if (pid != info->si_pid)
    {
        pid = info->si_pid;
        nbr = 0;
        cnt = 0;
    }
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
    ft_putstr_fd("sever PID:",1);
    ft_putnbr_fd(getpid(), 1);
    struct sigaction sa;
    sigemptyset(&sa.sa_mask); 
    if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 || sigaddset(&sa.sa_mask, SIGUSR2) == -1)
    {
        ft_putstr_fd("Error Occured\n", 1);
        exit(EXIT_FAILURE);
    }
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &signal_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_putstr_fd("Error Occured\n", 1);
        exit(EXIT_FAILURE);
    }
    while(1)
        pause();
    return(0);
}