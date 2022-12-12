/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_v1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:12:43 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/12 13:39:11 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t   g_flag = 0;

void    signal_handler(int sig)
{
    if(sig == ONEBIT)
        ft_putstr_fd("FINISHED",1);
    g_flag = sig;
}

void send_sig_to_server(pid_t pid, size_t len, const char *str)
{
    size_t  i;
    size_t  j;
    char    ch;
    
    i = 0;
    while (i <= len)
    {
        j = 0;
        ch = str[i];
        if (i == len)
            ch == 0x03;
        while (j < 8)
        {
            if ((ch & 0b00000001) == 1)
                kill (pid, ONEBIT);
            else 
                kill (pid, ZEROBIT);
            j++;
            ch = ch >> 1;
            while (g_flag == 0)
                ;
            g_flag = 0;
        }
        i++;
    }
}

int main(int argc, char const *argv[])
{
    pid_t               pid;
    struct sigaction    sa;
    
    if (argc != 3)
    {
        ft_putstr_fd("WRONG ARG", 1);
        return (0);
    }
    pid = ft_atoi(argv[1]);
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL == -1) || sigaction(SIGUSR2, &sa, NULL == -1))
    {
        ft_putstr_fd("SIGACTION ERROR OCCURED", 1);
        return (0);
    }
    send_sig_to_server(pid, ft_strlen(argv[2]), argv[2]);
    return (0);
}
