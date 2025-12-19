/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_b_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:09 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/19 12:15:35 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_int_arr	*full_check(int argc, char **argv)
{
	int			len;
	int			*data;
	t_int_arr	*stash;

	if (argc < 2)
		return (NULL);
	if (check_emt(argc, argv) == 0)
		return (write(2, "Error\n", 6), NULL);
	len = get_size(argv);
	if (len <= 0)
		return (write(2, "Error\n", 6), NULL);
	data = set_stash(argv);
	if (!data)
		return (write(2, "Error\n", 6), NULL);
	if (check_dup(data, len))
		return (free (data), write(2, "Error\n", 6), NULL);
	stash = malloc(sizeof(t_int_arr));
	if (!stash)
		return (NULL);
	stash->array = data;
	stash->size = len;
	return (stash);
}

int	check_emt(int argc, char **argv)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] > 32)
				x++;
			j++;
		}
		if (x == 0 || x >= 17)
			return (0);
		i++;
		j = 0;
		x = 0;
	}
	return (1);
}

int	*ft_intcpy(int *dest, int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size_t)-1 / size < nmemb)
		return (NULL);
	size = nmemb * size;
	mem = (char *) malloc(sizeof(char) * size);
	if (mem == 0)
		return (NULL);
	while (size > 0)
	{
		mem[i] = 0;
		i++;
		size--;
	}
	return (mem);
}

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
	free (stash);
	return (stack);
}
