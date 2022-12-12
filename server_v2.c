#include "minitalk.h"

volatile sig_atomic_t g_lst[2] = {0, 0};

int ft_power(int a, size_t n)
{
    if (n == 0)
        return (1);
    else if (n == 1)
        return (a);
    else
        return (a * ft_power(a, n - 1));
}

void signal_handler(int sig, siginfo_t *info, void *p)
{
    const pid_t pid = info->si_pid;
    
    if (pid == 0)
        exit (EXIT_FAILURE);
    (void)p;
    if (sig == SIGUSR2)
        g_lst[CHAR] += ft_power(2, g_lst[TIMES]);
    if (g_lst[TIMES] == 7 && g_lst[CHAR] == 0x03)
    {
        ft_putstr_fd("\n", 1);
        g_lst[CHAR] = 0;
        g_lst[TIMES] = 0;
        kill(info->si_pid, SIGUSR2);
        return ;
    }
    if (g_lst[TIMES] < 7)
        g_lst[TIMES]++;
    else
    {
        ft_putstr_fd(g_lst[CHAR], 1);
        g_lst[CHAR] = 0;
        g_lst[TIMES] = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;    
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_putstr_fd("PID: ",1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n",1);
    while (1)
        pause();
    return (0);
}