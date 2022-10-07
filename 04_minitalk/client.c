/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:02:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/08 01:20:16 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pid string
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void    ft_bitSignal(int pid, char c)
{
    int i = 7;
    int bit;

    while (i >= 0)
    {
        bit = c >> i & 1;
        if (bit == 0)
        {
            printf("시그널 보낸다! %d\n", bit);
            if (kill(pid, SIGUSR1) == -1)
                printf("시그널 보내기 실패!");
        }
        else if (bit == 1)
        {
            printf("시그널 보낸다! %d\n", bit);
            if (kill(pid, SIGUSR2) == -1)
                printf("시그널 보내기 실패!");
        }
        i--;
    }
}

int main(int argc, char* argv[])
{
    int pid = 0;
    int i = 0;

    if (argc < 3)
        return (0);
    while (argv[1][i] != '\0')
    {
        pid = pid * 10 + (argv[1][i] - 48);
        i++;
    }
    printf("pid: %d\n", pid);
    i = 2;
	while (argv[i] != 0)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            ft_bitSignal(pid, argv[i][j]);
            j++;
        }
        i++;
        if (argv[i] != 0)
            printf(" ");
    }

    return (0);
}