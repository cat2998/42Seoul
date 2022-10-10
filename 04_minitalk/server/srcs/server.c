/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:16:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/10 19:53:43 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	g_string;

void	ft_printf(int n)
{
	char	str;

	if (n >= 10)
	{
		ft_printf(n / 10);
		str = n % 10 + 48;
	}
	else
		str = n + 48;
	write(1, &str, 1);
	return ;
}

void	bit_handle(int signo)
{
	if (signo == SIGUSR1)
		g_string = g_string << 1 | 0;
	else if (signo == SIGUSR2)
		g_string = g_string << 1 | 1;
	return ;
}

int	main(void)
{
	int	i;

	ft_printf(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, bit_handle);
	signal(SIGUSR2, bit_handle);
	i = 0;
	while (1)
	{
		if (i < 8)
		{
			pause();
			i++;
		}
		else
		{
			if (g_string == 127)
				write(1, "\n", 1);
			else
				write(1, &g_string, 1);
			g_string = 0;
			i = 0;
		}
	}
}
