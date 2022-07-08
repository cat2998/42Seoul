/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:40:47 by jgwon             #+#    #+#             */
/*   Updated: 2022/07/08 22:46:15 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t  ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif