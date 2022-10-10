/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:02:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/10 19:55:36 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	bit_signal(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = c >> i & 1;
		if (bit == 0)
		{
			kill(pid, SIGUSR1);
			usleep(10);
		}
		else if (bit == 1)
		{
			kill(pid, SIGUSR2);
			usleep(10);
		}
		i--;
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	if (argc != 3)
		return (0);
	while (argv[1][i] != '\0')
	{
		pid = pid * 10 + (argv[1][i] - 48);
		i++;
	}
	if (pid < 100 || 99999 < pid)
		return (0);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_signal(pid, argv[2][i]);
		i++;
	}
	bit_signal(pid, 127);
	return (0);
}
