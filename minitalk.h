/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:29 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/13 13:02:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define CHAR 0
# define CNT  1
# define ZEROBIT SIGUSR1
# define ONEBIT SIGUSR2
# define ACKSIG SIGUSR1
# define CMPSIG SIGUSR2

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include "libft/libft.h"

#endif