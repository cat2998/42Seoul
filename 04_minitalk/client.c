/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:02:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/09 01:52:45 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// char    itoa_signal(int pid, int n)
// {
//     if (n >= 10)
//     {
//         itoa(n / 10);
//         n = n % 10 + 48;
//     }
//     else
//         n = n + 48;
//     bit_signal(pid, n);
// }

void    bit_signal(int pid, char c)
{
    int i;
    int bit;

    i = 7;
    while (i >= 0)
    {
        bit = c >> i & 1;
        if (bit == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                write(1, "killerror", 9);
            usleep(30);
        }
        else if (bit == 1)
        {
            if (kill(pid, SIGUSR2) == -1)
                write(1, "killerror", 9);
            usleep(30);
        }
        i--;
        usleep(125);
    }
}

int main(int argc, char* argv[])
{
    int i;
    int pid;

    i = 0;
    pid = 0;
    if (argc != 3)
        return (0);
    while (argv[1][i] != '\0')
    {
        pid = pid * 10 + (argv[1][i] - 48);
        i++;
    }
    if (pid < 100 || 99999 < pid)
        return (0);
    // i = 0;
    // while (argv[2][i] != '\0')
    //     i++;
    // itoa_signal(pid, i);
    // bit_signal(pid, 127);
    i = 0;
    while (argv[2][i] != '\0')
    {
        bit_signal(pid, argv[2][i]);
        i++;
    }
    bit_signal(pid, 127);

    return (0);
}