#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((n * -1), fd);
	}
	else if (0 <= n && n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
	else if (10 <= n)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
}

static unsigned int	ft_isspace(int c);
static const char	*ft_skipspace(const char *str);
static const char	*ft_flag(const char *str, int *sign);
static int	ft_isdigit(int c);

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

static	unsigned int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static const char	*ft_skipspace(const char *str)
{
	while (ft_isspace(*str) == 1)
		str++;
	return (str);
}

static const char	*ft_flag(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char	*str)
{
	size_t			n;
	int				flag;
	size_t			ov_dev;
	int				ov_mod;

	n = 0;
	str = ft_flag(ft_skipspace(str), &flag);
	ov_dev = LONG_MAX;
	ov_mod = ov_dev % 10;
	ov_dev = ov_dev / 10;
	while (ft_isdigit(*str) == 1)
	{
		if (n > ov_dev || (n == ov_dev && (*str - '0') > ov_mod))
		{
			if (flag == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		n = n * 10 + (*str++ - '0');
	}
	if (flag == -1)
		n *= -1;
	return ((int)n);
}