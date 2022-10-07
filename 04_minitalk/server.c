/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:16:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/07 23:09:25 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_printf(unsigned int n)
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

int main(void)
{
    ft_printf(getpid());
    printf("\n%d\n", getpid());
}