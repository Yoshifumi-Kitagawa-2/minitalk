/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:03:20 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/20 15:05:06 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include "libft/libft.h"

# define ZEROBIT SIGUSR1
# define ONEBIT SIGUSR2
# define ACKSIG SIGUSR1
# define CMPSIG SIGUSR2
# define EOT  4
# define MAX_SIZE 100

#endif