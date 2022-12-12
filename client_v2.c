#include "minitalk.h"

volatile sig_atomic_t g_flag = 0;

void    signal_handler(int sig)
{
    if (sig == SIGUSR2)
        ft_putstr_fd("FINISHED!", 1);
    g_flag = sig;
}

void    send_signal_to_server(pid_t pid, size_t len, const char *str)
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
            ch = 0x03;
        while (j < 8)
        {
            if ((ch & 0b00000001) == 1)
                kill (pid, SIGUSR2);
            else
                kill (pid, SIGUSR1);
            ++j;
            ch = ch >> 1;
            while (g_flag == 0)
                ;
            g_flag = 0;
        }
        ++i;
    }
}

int main(int argc, char const *argv[])
{
    pid_t   pid;
    struct sigaction    sa;

    if (argc != 3)
    {
        ft_putstr_fd("./client PID STR  type like this", 1);
        return (0);
    }
    pid = ft_atoi(argv[1]);
    /*
    if (kill(pid, 0))
    {
        if (errno == EPERM)
            ft_printf("pid exists but there isn't right to send signal it\n");
        else if (errno == ESRCH)
            ft_printf("pid dosen't exist");
        return (0);
    }   
    */
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    send_signal_to_server(pid, ft_strlen(argv[2]), argv[2]);
    return (0);
}