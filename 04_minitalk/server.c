/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:16:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/08 01:20:19 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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
    printf("0");
}

void oneBit()
{
    printf("1");
}

int main(void)
{
    ft_printf(getpid());
    printf("\n");

    sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);

    signal(SIGUSR1, zeroBit);
    signal(SIGUSR2, oneBit);
    while (1)
    {
        write(1, "waiting~\n", 9);
        pause();
        write(1, "get!\n", 5);
    }
}