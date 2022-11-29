/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:35:56 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/29 21:29:29 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	char	str;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		str = n % 10 + 48;
	}
	else
		str = n + 48;
	write(1, &str, 1);
	return ;
}

void	err(char *str, t_game *game)
{
	int	i;
	int	size;

	write(2, "Error\n", 6);
	size = ft_strlen(str);
	i = 0;
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	free(game->board);
	free(game->map_str);
	free(game);
	exit(0);
}
