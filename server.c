/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:35:39 by tytang            #+#    #+#             */
/*   Updated: 2022/09/23 13:00:26 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	handler(int sig_num)
{
	static int	location;
	static int	byte;

	if (sig_num == SIGUSR1)
		byte += 1 << (7 - location);
	location++;
	if (location == 8)
	{
		ft_putchar(byte);
		location = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("not enough arguments\n");
		return (0);
	}
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("pid: %d\n", pid);
		ft_printf("message: \n");
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while (1)
			pause();
	}
	return (0);
}
