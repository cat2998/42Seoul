/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:54:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/26 23:11:02 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

void ft_atoi(char *argv)
{
    int i;
    int minus;
    int flag;
    long result;

    i = 0;
    minus = 0;
    flag = 0;
    result = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] == ' ' && flag == 1)
        {
            if (minus == 1)
                result *= -1;
            if (-2147483648 <= result && result <= 2147483647)
                //push stack
            flag = 0;
            result = 0;
        }
        else if ((argv[i] == '+' || argv[i] == '-') && flag == 0)
        {
            if (argv[i] == '-')
                minus = 1;
            result = 0;
        }
        else if (48 <= argv[i] && argv[i] <= 57)
        {
            result = result * 10 + argv[i] - 48;
            flag = 1;
        }
        else
        {
            write(1, "Error\n", 6);
            //free
            exit(0);
        }
        i++;
    }
    if (flag == 1)
    {
        if (minus == 1)            
            result *= -1;
        if (-2147483648 <= result && result <= 2147483647)
        {
            //push stack
        }
    }
    return ;
}

int main(int argc, char *argv[])
{
    t_stack *stackA;

    stackA = malloc(sizeof(t_stack) * 1);
	if (!stackA)
		return (0);
    init_stack(stackA);
    while (argc > 1)
    {
        ft_atoi(argv[argc - 1]);
        argc--;
    }
    return (0);
    // quick_sork()
}