/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:34:32 by jgwon             #+#    #+#             */
/*   Updated: 2022/12/26 22:42:30 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include <stdio.h>

typedef struct s_table
{
	int number;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int must_eat;
	t_philosopher	*philosophers;
} t_table;

typedef struct s_philosopher
{
	int state;	// 0:먹기 1:생각하기 2:잠자기
	int time;
} t_philosopher;


#endif