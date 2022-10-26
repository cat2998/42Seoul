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

void print_error(void)
{
    write(1, "Error\n", 6);
    return ;
}

long ft_atoi(char *argv)
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
        if (argv[i] == ' ')
            result = 0;
        else if (48 <= argv[i] && argv[i] <= 57)
            result = result * 10 + argv[i] - 48;
        else
        {
            write(1, "1", 1);
            exit(0);
        }
        i++;
    }
    if (minus == 1)
        result *= -1;
    if (-2147483648 <= result && result <= 2147483647)
        return result;
    else
        exit(0);
}

int main(int argc, char *argv[])
{
    t_stack *stackA;

    atexit(print_error);
    init_stack(stackA);

    while (argc > 1)
    {
        ft_atoi(argv[argc - 1]);
        argc--;
    }
    // quick_sork()
}