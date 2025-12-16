/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_b_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:09 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 13:56:31 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_int_arr	*full_check(int argc, char **argv)
{
	int			len;
	int			*data;
	t_int_arr	*stash;

	if (argc < 2)
		return (NULL);
	len = get_size(argv);
	if (len <= 0)
		return (write(1, "Error\n", 6), NULL);
	data = set_stash(argv);
	if (!data)
		return (write(1, "Error\n", 6), NULL);
	if (check_dup(data, len))
		return (free (data), write(1, "Error\n", 6), NULL);
	stash = malloc(sizeof(t_int_arr));
	if (!stash)
		return (NULL);
	stash->array = data;
	stash->size = len;
	return (stash);
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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size_t)-1 / size < nmemb)
		return (NULL);
	mem = (char *) malloc(sizeof(char) * (nmemb * size));
	if (mem == 0)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
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
