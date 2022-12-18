/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:36:35 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/18 15:49:09 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"
#include <stdio.h>

t_signal    g_signal;

void signal_handler(int signal, siginfo_t *info, void *context)
{
    const pid_t pid = info->si_pid;
    
    (void)context;
    if (signal == ONEBIT)
        g_signal.nbr = (g_signal.nbr << 1) | 1;
    else if (signal == ZEROBIT)
        g_signal.nbr = g_signal.nbr << 1;
    if (g_signal.cnt == 8)
    {
        if (g_signal.nbr == EOT)
        {
            kill(pid, CMPSIG);
            return ;
        }
        ft_putchar_fd(g_signal.nbr, 1);
        g_signal.nbr = 0;
        g_signal.cnt = 0;
    }
    else
        g_signal.cnt++;
    kill(pid, ACKSIG);
}

int main(void)
{
    g_signal.nbr = 0;
    g_signal.cnt = 0;
    struct sigaction    sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_putstr_fd("PID:", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n",1);
    while(1)
        pause();
    return(0);
}