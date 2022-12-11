/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:34:32 by jgwon             #+#    #+#             */
/*   Updated: 2022/12/11 21:37:27 by jgwon            ###   ########.fr       */
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
    int *fork;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
} t_table;

typedef struct s_philosopher
{
    int *state;
    int eat;
} t_philosopher;


#endif