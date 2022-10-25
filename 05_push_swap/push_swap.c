/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:54:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/23 16:37:00 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

long atoi_is_int(char *argv)
{
    int i;
    int minus;
    long result;

    i = 0;
    minus = 0;
    result = 0;
    if (argv[0] == '-')
    {
        i = 1;
        minus = 1;
    }
    while (argv[i] != '\0')
    {
        if (48 <= argv[i] && argv[i] <= 57)
            result = result * 10 + argv[i] - 48;
        else
            return 3000000000;
        i++;
    }
    if (minus == 1)
        result *= -1;
    if (-2147483648 <= result && result <= 2147483647)
        return result;
    else
        return 3000000000;
}

int main(int argc, char *argv[])
{
    t_stack stackA;

    init_stack(stackA);

    // int *list;
    // list = (int *)malloc(sizeof(int) * (argc - 1));
    while (argc > 1)
    {
        atoi_is_int(argv[argc - 1]);
        argc--;
    }
    // for (int j = 0; j < argc - 1; j++)
    // {
    //     printf("list[%d]: %d\n", j, list[j]);
    // }
    // quick_sork()
}