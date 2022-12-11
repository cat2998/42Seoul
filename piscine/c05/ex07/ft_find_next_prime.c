/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:34 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/20 11:23:36 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);
int	ft_sqrt(int nb);

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb % 2 == 0 && nb != 2)
		return (0);
	i = 2;
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	min;
	int	max;
	int	result;

	min = 0;
	max = 46340;
	while (min <= max)
	{
		result = (min + max) / 2;
		if (result * result == nb)
			return (result);
		else if (result * result > nb)
			max = result - 1;
		else
			min = result + 1;
	}
	return (max);
}
