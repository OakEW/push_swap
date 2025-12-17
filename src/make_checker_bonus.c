/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:47 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/17 17:09:33 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sort(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_b != 0)
		return (write (1, "KO\n", 3));
	while (i < stack->size_a - 1 && stack->a[i] < stack->a[i + 1])
		i++;
	if (i == stack->size_a - 1)
		return (write (1, "OK\n", 3));
	else
		return (write (1, "KO\n", 3));
}

int	do_op(char *buffer, t_stack *stack, int i)
{
	if (buffer[i] == 's' && buffer[i + 1] == 'a')
		sa(stack);
	else if (buffer[i] == 's' && buffer[i + 1] == 'b')
		sb(stack);
	else if (buffer[i] == 's' && buffer[i + 1] == 's')
		ss(stack);
	else if (buffer[i] == 'r' && buffer[i + 1] == 'a')
		ra(stack);
	else if (buffer[i] == 'r' && buffer[i + 1] == 'b')
		rb(stack);
	else if (buffer[i] == 'r' && buffer[i + 1] == 'r')
		rr(stack);
	else if (buffer[i] == 'p' && buffer[i + 1] == 'a')
		pa(stack);
	else if (buffer[i] == 'p' && buffer[i + 1] == 'b')
		pb(stack);
	else
		return (-1);
	return (1);
}

int	do_op_2(char *buffer, t_stack *stack, int i)
{
	if (buffer[i] == 'r' && buffer[i + 1] == 'r' && buffer[i + 2] == 'a')
		rra(stack);
	else if (buffer[i] == 'r' && buffer[i + 1] == 'r' && buffer[i + 2] == 'b')
		rrb(stack);
	else if (buffer[i] == 'r' && buffer[i + 1] == 'r' && buffer[i + 2] == 'r')
		rrr(stack);
	else
		return (-1);
	return (1);
}

int	check_buffer(char *buffer, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != 0)
	{
		while (buffer[i] != '\n' && buffer[i] != 0)
			i++;
		if (!(i - j == 2 || i - j == 3))
			return (write (2, "Error\n", 6));
		else if (i - j == 2 && do_op(buffer, stack, j) < 0)
			return (write (2, "Error\n", 6));
		else if (i - j == 3 && do_op_2(buffer, stack, j) < 0)
			return (write (2, "Error\n", 6));
		if (buffer[i] != '\n')
			return (write (2, "Error\n", 6));
		i++;
		j = i;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		byte;
	int		x;
	char	*buffer;

	buffer = ft_calloc(30000, 1);
	if (!buffer)
		return (0);
	x = 0;
	byte = 1;
	stack = set_stack(argc, argv);
	if (!stack)
		return (free (buffer), 0);
	while (byte != 0)
	{
		byte = read(0, &buffer[x], 10);
		x += byte;
	}
	if (check_buffer(buffer, stack) == 0)
		check_sort(stack);
	free (buffer);
	free (stack->a);
	free (stack->b);
	free (stack);
}
