/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:13 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/14 00:21:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_flag = 0;

void signal_handler(int signal, siginfo_t *info, void *context)
{
    (void)context;
    
}

bool send_signal(pid_t server_pid, char *str, size_t len)
{
    size_t  i;
    size_t  j;
    char    chr;
    
    i = 0;
    while (i < len)
    {
        j = 0;
        chr = str[i];
        if (i == len)
            chr = EOT;
        while (j < 8)
        {
            if ((chr & 0b00000001) == 0)
                kill(server_pid, ZEROBIT);
            else
                kill(server_pid, ONEBIT);
            j++;
            chr = chr >> 1;
            while ()
        }
        i++;
    }
    send_byte(server_pid, EOT);
    return(true);
}

int main(int argc, char const*argv[])
{
    pid_t server_pid;
    struct sigaction sa;
    
    server_pid = ft_atoi(argv[1]);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    send_signal(server_pid, argv[2], ft_strlen(argv[2]));
    return (0);
}