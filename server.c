/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:12:45 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/08 18:05:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signal, siginfo_t *info, void *context)
{
    static int pid = 0;

    (void)context;
    if (info->si_pid)
        pid = info->si_pid;
    
    
}

int main(void)
{
    struct sigaction    sa;
    sa.sa_handler = 0;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
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
}