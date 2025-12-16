/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:11:40 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 18:11:57 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a <= 1)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
}

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = stack->a[0];
	if (stack->size_a <= 1)
		return ;
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
}

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size_a;
	tmp = stack->a[stack->size_a - 1];
	if (stack->size_a <= 1)
		return ;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[i] = tmp;
}

void	pa(t_stack *stack)
{
	int	tmp;
	int	i;

	i = -1;
	if (stack->size_b == 0)
		return ;
	tmp = stack->b[0];
	stack->b[0] = 0;
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->size_b--;
	stack->size_a++;
	i = stack->size_a;
	stack->a[stack->size_a - 1] = tmp;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[i] = tmp;
}
