/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:16:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/09 01:53:07 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

static char string;

void	ft_printf(unsigned int n)
{
	char	str;

	if (n >= 10)
	{
		ft_printf(n / 10);
		str = n % 10 + 48;
	}
	else
		str = n + 48;
	write(1, &str, 1);
	return ;
}

void    zeroBit()
{
    string = string << 1 | 0;
}

void oneBit()
{
    string = string << 1 | 1;
}

long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(void)
{
    int i;
    long start, end;

    ft_printf(getpid());
    write(1, "\n", 1);

    signal(SIGUSR1, zeroBit);
    signal(SIGUSR2, oneBit);
    i = 0;
    int j = 0;
    while (1)
    {
        if (i < 8)
        {
            pause();
            if (i == 0 && j == 0)
            {
                start = getMicrotime();
                j++;
            }
            i++;
        }
        else
        {
            if (string == 127)
            {
                write(1, "\n", 1);
                end = getMicrotime();
                printf("time : %ld\n", (end - start) / 1000);
                j = 0;
            }
            else
            {
                write(1, &string, 1);
            }
            string = 0;
            i = 0;
        }
    }
}