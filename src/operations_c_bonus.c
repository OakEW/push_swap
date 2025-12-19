/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_c_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:13:25 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/19 13:09:17 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

int	Longer_long(int argc, char **argv)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] != '0' && is_valid(&argv[i][j]))
				x++;
			j++;
			if (argv[i][j] <= 32 && x <= 11)
				x = 0;
		}
		if (x > 11)
			return (0);
		i++;
		j = 0;
		x = 0;
	}
	return (1);
}
