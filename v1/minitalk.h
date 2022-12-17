/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:29 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/17 20:02:06 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include "libft/libft.h"

# define CHAR 0
# define CNT  1
# define ZEROBIT SIGUSR1
# define ONEBIT SIGUSR2
# define ACKSIG SIGUSR1
# define CMPSIG SIGUSR2
# define EOT  4

typedef struct s_signal
{
    size_t nbr;
    int cnt;
}t_signal;

#endif