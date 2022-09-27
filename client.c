/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:36:19 by tytang            #+#    #+#             */
/*   Updated: 2022/09/23 11:29:22 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	ctr;
	long	outcome;

	sign = 0;
	ctr = 0;
	outcome = 0;
	while ((str[ctr] != '\0') && (str[ctr] == 32 || str[ctr] == '\t'
			|| str[ctr] == '\n' || str[ctr] == '\r' || str[ctr] == '\v'
			|| str[ctr] == '\f'))
		ctr++;
	if ((str[ctr] != '\0') && (str[ctr] == '-'))
	{
		sign = 1;
		ctr++;
	}
	else if (str[ctr] == '+')
		ctr++;
	while ((str[ctr] != '\0') && ((str[ctr] >= '0') && (str[ctr] <= '9')))
	{
		outcome = (outcome * 10) + (str[ctr++] - '0');
	}
	if (sign == 1)
		return (-outcome);
	return (outcome);
}

void	send_to_server(char c, int pid)
{
	int	bit_idx;

	bit_idx = 7;
	while (bit_idx >= 0)
	{
		if (c >> bit_idx & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(25);
		bit_idx--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	str_ctr;

	str_ctr = 0;
	if (argc != 3)
	{
		ft_printf("not enough arguments | ./client <pid> <string>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("invalid pid");
		return (0);
	}
	while (argv[2][str_ctr])
	{
		send_to_server(argv[2][str_ctr++], pid);
	}
	return (1);
}
