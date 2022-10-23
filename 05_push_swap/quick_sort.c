/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:37:10 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/23 20:59:20 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_printf(int list[])
{
    int i = 0;
    while (i < 10)
    {
        printf("%d ", list[i]);
        i++;
    }
    printf("\n");
    return ;
}

void    swap(int list[], int lo, int hi)
{
    int temp;

    temp = list[lo];
    list[lo] = list[hi];
    list[hi] = temp;
    return ;
}

int partition(int list[], int lo, int hi)
{
    int pivot;

    pivot = lo;
    while (lo < hi)
    {
        while (list[hi] > list[pivot] && lo < hi)
            hi--;
        while (list[lo] <= list[pivot] && lo < hi)
            lo++;
        swap(list, lo, hi);
    }
    swap(list, pivot, lo);
    return (lo);
}

void quick_sort(int list[], int lo, int hi)
{
    int pivot;

    if (lo >= hi)
        return ;
    pivot = partition(list, lo, hi);
    quick_sort(list, lo, pivot - 1);
    quick_sort(list, pivot + 1, hi);
    return ;
}

int main(void)
{
    int list[10] = {3,6,2,7,1,3,4,10,9,-1};
    quick_sort(list, 0, 9);
    ft_printf(list);
}