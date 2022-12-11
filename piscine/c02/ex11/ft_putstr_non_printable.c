/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:17:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/13 14:31:09 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexa(unsigned char str);

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 127)
		{
			write (1, "\\", 1);
			ft_hexa(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	ft_hexa(unsigned char str)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[str / 16], 1);
	write(1, &hexa[str % 16], 1);
}
