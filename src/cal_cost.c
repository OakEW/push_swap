/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:52:44 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/18 16:11:48 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

int	cal_cost(int x, t_stack *stack, char flag)
{
	int	cost;
	int	*in_target;
	int	sizea;
	int	sizeb;

	in_target = stack->in_b;
	sizea = stack->size_a;
	sizeb = stack->size_b;
	if (flag == 'a')
	{
		in_target = stack->in_a;
		sizea = stack->size_b;
		sizeb = stack->size_a;
	}
	cost = in_target[x];
	if (x > sizea / 2)
		x = x - sizea;
	if (cost > sizeb / 2)
		cost = cost - sizeb;
	if ((x >= 0 && cost >= 0 && x > cost) || (x < 0 && cost < 0 && x < cost))
		cost = x;
	else if ((x >= 0 && cost < 0) || (x < 0 && cost >= 0))
		cost = cost - x;
	return (cost);
}

int	locate_cheapest(t_stack *stack, char flag)
{
	int	x;
	int	cost;
	int	size;
	int	min;
	int	tmp;

	min = 0;
	size = stack->size_a;
	if (flag == 'a')
		size = stack->size_b;
	x = 0;
	tmp = ft_abs((cal_cost(0, stack, flag)));
	while (x < size)
	{
		cost = ft_abs(cal_cost(x, stack, flag));
		if (cost < tmp)
		{
			tmp = cost;
			min = x;
		}
		x++;
	}
	return (min);
}
