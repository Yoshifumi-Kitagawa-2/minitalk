/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:13 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/13 15:17:45 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signal, siginfo_t *info, void *context)
{
    (void)context;
    
}
void send_str(pid_t pid, char *argv[2], size_t argv2_strlen)
{
    
}

int main(int argc, char const*argv[])
{
    pid_t pid;
    struct sigaction sa;
    
    pid = ft_atoi(argv[1]);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    send_str(pid, argv[2], ft_strlen(argv[2]));
    return (0);
}