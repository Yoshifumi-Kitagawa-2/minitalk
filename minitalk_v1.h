/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_v1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:13:11 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/12 13:43:49 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_V1_H
# define MINITALK_V1_H

/*
# define ONEBIT     SIGUSR1
# define ZEROBIT    SIGUSR2
*/

# define CHAR 0
# define TIMES 1
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
int	    ft_atoi(const char	*str);

#endif
