/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:13:25 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/17 17:13:11 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b <= 1)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = stack->b[0];
	if (stack->size_b <= 1)
		return ;
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size_b;
	tmp = stack->b[stack->size_b - 1];
	if (stack->size_b <= 1)
		return ;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = tmp;
}

void	pb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = -1;
	if (stack->size_a == 0)
		return ;
	tmp = stack->a[0];
	stack->a[0] = 0;
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->size_a--;
	stack->size_b++;
	i = stack->size_b;
	stack->b[stack->size_b - 1] = tmp;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = tmp;
}
