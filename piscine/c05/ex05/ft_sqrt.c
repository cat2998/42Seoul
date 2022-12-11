/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:08:52 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/20 11:17:56 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}
