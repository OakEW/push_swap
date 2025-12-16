/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:42:09 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 12:33:55 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_stack(int argc, char **argv)
{
	t_int_arr	*stash;
	t_stack		*stack;

	stash = full_check(argc, argv);
	if (!stash)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = stash->array;
	stack->b = ft_calloc(1, (sizeof(int) * stash->size));
	if (!stack->b)
		return (NULL);
	stack->size_a = stash->size;
	stack->size_b = 0;
	stack->in_b = ft_calloc(1, (sizeof(int) * stash->size));
	if (!stack->in_b)
		return (NULL);
	stack->in_a = ft_calloc(1, (sizeof(int) * stash->size));
	if (!stack->in_a)
		return (NULL);
	free (stash);
	return (stack);
}

void	find_index(t_stack *stack)
{
	int	x;

	x = 0;
	while (x < stack->size_a)
	{
		get_in_b(x, stack);
		x++;
	}
	x = 0;
	while (x < stack->size_b)
	{
		get_in_a(x, stack);
		x++;
	}
}

void	get_in_b(int x, t_stack *stack)
{	
	int	i;
	int	tar;
	int	max;

	i = -1;
	max = 0;
	tar = 0;
	if (stack->size_b == 0)
		stack->in_b[x] = 0;
	while (++i < stack->size_b)
	{
		if (stack->b[i] > stack->b[max])
			max = i;
		if (stack->b[tar] > stack->a[x])
			tar = i;
		if (stack->b[i] < stack->a[x] && stack->b[i] > stack->b[tar])
			tar = i;
	}
	if (stack->b[tar] > stack->a[x])
		tar = max;
	stack->in_b[x] = tar;
}

void	get_in_a(int x, t_stack *stack)
{
	int	i;
	int	tar;
	int	min;

	i = -1;
	min = 0;
	tar = 0;
	if (stack->size_a == 0)
		stack->in_a[x] = 0;
	while (++i < stack->size_a)
	{
		if (stack->a[i] < stack->a[min])
			min = i;
		if (stack->a[tar] < stack->b[x])
			tar = i;
		if (stack->a[i] > stack->b[x] && stack->a[i] < stack->a[tar])
			tar = i;
	}
	if (stack->a[tar] < stack->b[x])
		tar = min;
	stack->in_a[x] = tar;
}
