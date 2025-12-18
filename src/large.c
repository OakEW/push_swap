/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:29:31 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/18 14:16:11 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intcpy(int *dest, int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_sorting(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 0;
	while (j < size - 1)
	{
		while (i < size)
		{
			if (array[j] < array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				i = j + 1;
			}
			i++;
		}
		j++;
		i = j + 1;
	}
}

void	median(t_stack *stack)
{
	int	*array;
	int	m;

	array = ft_calloc(stack->size_a, sizeof(int));
	if (!array)
		return ;
	ft_intcpy(array, stack->a, stack->size_a);
	ft_sorting(array, stack->size_a);
	m = array[stack->size_a / 2];
	free (array);
	while (stack->size_a > 3)
	{
		if (stack->a[0] >= m)
			pb(stack);
		else
		{
			pb(stack);
			rb(stack);
		}
	}
}
