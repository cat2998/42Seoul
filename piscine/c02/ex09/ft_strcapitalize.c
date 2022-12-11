/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:28:16 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/12 17:43:12 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strupcase(int i, char *str);
void	ft_strlowcase(int i, char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (flag == 0)
		{
			ft_strupcase(i, str);
			flag = 1;
		}
		else if (flag == 1)
			ft_strlowcase(i, str);
		if (str[i] < 48 || (57 < str[i] && str[i] < 65))
			flag = 0;
		else if ((90 < str[i] && str[i] < 97) || str[i] > 122)
			flag = 0;
		i++;
	}
	return (str);
}

void	ft_strupcase(int i, char *str)
{
	if ('a' <= str[i] && str[i] <= 'z')
		str[i] -= 32;
}

void	ft_strlowcase(int i, char *str)
{
	if ('A' <= str[i] && str[i] <= 'Z')
		str[i] += 32;
}
