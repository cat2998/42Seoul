/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:02:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/07 23:33:45 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pid string
#include <stdio.h>

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
    i = 0;
	while (argv[2][i] != '\0')
    {
        i++;
    }
    printf("string length: %d\n", i);

    return (0);
}