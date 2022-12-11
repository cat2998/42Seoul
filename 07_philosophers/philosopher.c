/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:38:12 by jgwon             #+#    #+#             */
/*   Updated: 2022/12/11 21:45:28 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_table 		*table;
	t_philosopher	*philosopher;

	if (argc != 5 && argc != 6)
		exit(1);
	table = malloc(sizeof(t_table) * 1);
	if (!table)
		exit(1);
	philosopher = malloc(sizeof(t_philosopher) * 1);
	if (!philosopher)
	{
		free(table);
		exit(1);
	}
	
}