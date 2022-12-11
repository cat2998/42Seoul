/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:01:56 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/16 14:58:06 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
