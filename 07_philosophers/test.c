/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:12:20 by jgwon             #+#    #+#             */
/*   Updated: 2022/12/26 22:22:03 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	mutex;

static int mail = 0;

void	*test(void *data)
{
	pthread_mutex_lock(&mutex);
	mail += *(int *)data;
	printf("mail: %d\n", mail);
	pthread_mutex_unlock(&mutex);
}

int main(void)
{
	int			a;
	pthread_t	p1, p2;
	int			status;

	a = 100;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, test, (void *)&a) != 0)
	{
		printf("thread create error!");
		exit(0);
	}
	if (pthread_create(&p2, NULL, test, (void *)&a) != 0)
	{
		printf("thread create error!");
		exit(0);
	}
	pthread_join(p1, (void **)&status);
	pthread_join(p2, (void **)&status);
	pthread_mutex_destroy(&mutex);
	printf("mail : %d\n", mail);
	return (0);
}