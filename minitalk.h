/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:35:48 by tytang            #+#    #+#             */
/*   Updated: 2022/09/23 11:06:47 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf.h"

void	ft_putchar(char c);
void	handler(int num);
int		ft_atoi(const char *str);
void	send_to_server(char c, int pid);

#endif
