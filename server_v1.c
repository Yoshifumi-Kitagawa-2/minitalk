/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_v1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:12:45 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/12 13:42:11 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_v1.h"

volatile sig_atomic_t   g_list[2] = {0, 1};

#define CHAR 0
#define CNT  1

void signal_handler(int signal, siginfo_t *info, void *context)
{
    const pid_t pid = info->si_pid;
    
    if (pid == 0)
        exit(EXIT_FAILURE);
    (void)context;
    if (signal == ZEROBIT)
        g_list[CHAR] = g_list[CHAR] << 1;
    else if (signal == ONEBIT)
        g_list[CHAR] = g_list[CHAR] << 1 | 1;
    if (g_list[CNT] == 8 && g_list[CHAR] == 0x03)
    {
        kill(info->si_pid, ONEBIT);
        return ;
    }
    else if (g_list[CNT] < 8)
        g_list[CNT]++;
    else
    {
        ft_putchar_fd(g_list[CHAR], 1);
        g_list[CHAR] = 0;
        g_list[CNT] = 1;
    }
    kill(info->si_pid, ZEROBIT);
}

int main(void)
{
    struct sigaction    sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_putstr_fd("server: unexpected error.\n", 1);
        return (0);
    }
    ft_putstr_fd("PID: ",1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n",1);
    while(1)
        pause();
    return(0);
}