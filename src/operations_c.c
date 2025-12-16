/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:13:25 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 18:20:48 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size_a;
	tmp = stack->a[stack->size_a - 1];
	if (stack->size_a > 1)
	{
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = tmp;
	}
	i = stack->size_b;
	tmp = stack->b[stack->size_b - 1];
	if (stack->size_b > 1)
	{
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[i] = tmp;
	}
	find_index(stack);
	write(1, "rrr\n", 4);
}

void	rr(t_stack *stack)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = stack->a[0];
	if (stack->size_a > 1)
	{
		while (++i < stack->size_a - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = tmp;
	}
	i = -1;
	tmp = stack->b[0];
	if (stack->size_b > 1)
	{
		while (++i < stack->size_b - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = tmp;
	}
	find_index(stack);
	write(1, "rr\n", 3);
}

void	ss(t_stack *stack)
{
	int	tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if (stack->size_b > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	find_index(stack);
	write(1, "ss\n", 3);
}
