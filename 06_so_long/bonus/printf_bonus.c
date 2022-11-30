/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:35:56 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/30 23:40:17 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	return ;
}

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
	write(2, "Error\n", 6);
	ft_putstr(str);
	free(game->board);
	free(game->map_str);
	free(game);
	exit(0);
}
