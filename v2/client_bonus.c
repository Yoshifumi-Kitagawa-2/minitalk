/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:56:01 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/20 15:04:35 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t g_atomic_data = 0;

static void signal_handler(int signal)
{
    if (signal == CMPSIG)
    {
        g_atomic_data = CMPSIG;
        ft_putstr_fd("\nFINISHED!", 1);
    }
    else if (signal == ACKSIG)
        g_atomic_data = ACKSIG;
}

void send_byte(pid_t server_pid, char ch)
{
    size_t  cnt;

    cnt = 0;
    while(cnt < 8)
    {
        if ((ch & 0b00000001) == 0)
            kill(server_pid, ZEROBIT);
        else if ((ch & 0b00000001) == 1)
            kill(server_pid, ONEBIT);
        cnt++;
        ch = ch >> 1;
        while (g_atomic_data == 0)
            usleep(50);
        g_atomic_data = 0;
        usleep(500);
    }
}

void send_str(pid_t server_pid, const char *str, size_t len)
{
    size_t  cnt;
    
    cnt = 0;
    while (cnt < len)
    {
        send_byte(server_pid, str[cnt]);
        cnt++;
    }
    send_byte(server_pid, EOT);
}

int main(int argc, char const*argv[])
{
    if (argc != 3)
    {
        ft_putstr_fd("Error Occured\n", 1);
        exit(EXIT_FAILURE);
    }
    pid_t server_pid;
    struct sigaction sa;
    server_pid = ft_atoi(argv[1]);
    sa.sa_flags = 0;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_putstr_fd("Error Occured\n", 1);
        exit(EXIT_FAILURE);
    }
    send_str(server_pid, argv[2], ft_strlen(argv[2]));
    return (0);
}