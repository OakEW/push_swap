/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:52:44 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 12:30:00 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_roll_b(t_stack *stack, int i, int index)
{
	if (i == 0 && index == 0)
		return ;
	if (i > 0 && index > 0)
	{
		rr(stack);
		return ;
	}
	if (i < 0 && index < 0)
	{
		rrr(stack);
		return ;
	}
	if (i > 0)
		ra(stack);
	if (i < 0)
		rra(stack);
	if (index > 0)
		rb(stack);
	if (index < 0)
		rrb(stack);
}

void	smart_roll_a(t_stack *stack, int i, int index)
{
	if (i == 0 && index == 0)
		return ;
	if (i > 0 && index > 0)
	{
		rr(stack);
		return ;
	}
	if (i < 0 && index < 0)
	{
		rrr(stack);
		return ;
	}
	if (i > 0)
		rb(stack);
	if (i < 0)
		rrb(stack);
	if (index > 0)
		ra(stack);
	if (index < 0)
		rra(stack);
}

void	make_move_b(t_stack *stack, char flag)
{
	int	i;
	int	index;

	i = locate_cheapest(stack, flag);
	index = stack->in_b[i];
	if (i > stack->size_a / 2)
		i = i - stack->size_a;
	if (index > stack->size_b / 2)
		index = index - stack->size_b;
	while (!(i == 0 && index == 0))
	{
		smart_roll_b(stack, i, index);
		if (i > 0)
			i--;
		if (i < 0)
			i++;
		if (index > 0)
			index--;
		if (index < 0)
			index++;
	}
	pb(stack);
}

void	make_move_a(t_stack *stack, char flag)
{
	int	i;
	int	index;

	i = locate_cheapest(stack, flag);
	index = stack->in_a[i];
	if (i > stack->size_b / 2)
		i = i - stack->size_b;
	if (index > stack->size_a / 2)
		index = index - stack->size_a;
	while (!(i == 0 && index == 0))
	{
		smart_roll_a(stack, i, index);
		if (i > 0)
			i--;
		if (i < 0)
			i++;
		if (index > 0)
			index--;
		if (index < 0)
			index++;
	}
	pa(stack);
}
