/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:38:12 by jgwon             #+#    #+#             */
/*   Updated: 2022/12/26 23:32:38 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philosopher(t_table *table)
{
	int	i;

	i = 0;
	// while (i < table->number)
	// {
	// 	table->philosophers[i]
	// }
}

int init_table(t_table *table, int argc, char *argv[])
{
	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (1);
	table->number = argv[1];
	table->time_to_die = argv[2];
	table->time_to_eat = argv[3];
	table->time_to_sleep = argv[4];
	if (argc == 6)
		table->must_eat = argv[5];
	table->philosophers = malloc(sizeof(t_philosopher) * table->number);
	if (table->philosophers)
	{
		free(table);
		return (1);
	}
	init_philosopher(table);
	return (0);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_table 		*table;
	

	if (argc != 5 && argc != 6)
		exit(1);
	if (init_table(table, argc, argv))
		exit(1);
}