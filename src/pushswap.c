/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:58:41 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/18 16:07:41 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1 && stack->a[i] < stack->a[i + 1])
		i++;
	if (i == stack->size_a - 1)
		return (1);
	else
		return (0);
}

void	sort_three(t_stack *stack)
{
	if (stack->size_a == 1)
		return ;
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
		return ;
	}
	if (stack->a[0] < stack->a[2] && stack->a[2] < stack->a[1])
		rra(stack);
	else if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
		ra(stack);
	if (stack->a[0] > stack->a[1])
		sa(stack);
	if (stack->a[0] > stack->a[2])
		rra(stack);
}

void	fin_roll(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[tmp] < stack->a[i])
			tmp = i;
		i++;
	}
	if (tmp < stack->size_a / 2)
	{
		while (tmp-- > -1)
			ra(stack);
	}
	else
	{
		tmp = stack->size_a - tmp;
		while (--tmp > 0)
			rra(stack);
	}
}

void	push_swap(t_stack *stack)
{
	if (stack->size_a <= 3)
		return (sort_three(stack));
	else if (stack->size_a >= 300)
		median(stack);
	else
	{
		pb(stack);
		pb(stack);
		while (stack->size_a > 3)
			make_move_b(stack, 'b');
	}
	sort_three(stack);
	while (stack->size_b > 0)
	{
		make_move_a(stack, 'a');
	}
	fin_roll(stack);
}
// # include<stdio.h> 
// void	printf_s(t_stack *stack)
// {
// 	int	x;

// 	x = 0;
// 	printf("stack_a:\n");	
// 	while (x < (stack->size_a))
// 		printf ("%d\n", stack->a[x++]);
// 	printf("stack_b:\n");	
// 	x = 0;
// 	while (x < (stack->size_b))
// 		printf ("%d\n", stack->b[x++]);
// }

int	main(int argc, char **argv)
{
	t_stack		*stack;

	stack = set_stack(argc, argv);
	if (!stack)
		return (0);
	if (check_sort(stack))
		return (0);
	push_swap(stack);
	free (stack->a);
	free (stack->b);
	free (stack->in_a);
	free (stack->in_b);
	free (stack);
}
