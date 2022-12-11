/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:25:35 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/10 16:25:51 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tempa;
	int	tempb;

	tempa = *a;
	tempb = *b;
	*a = tempa / tempb;
	*b = tempa % tempb;
}
