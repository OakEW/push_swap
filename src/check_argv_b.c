/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:09 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/19 13:15:50 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_arr	*full_check(int argc, char **argv)
{
	int			len;
	int			*data;
	t_int_arr	*stash;

	if (argc < 2)
		return (NULL);
	if (check_emt(argc, argv) == 0)
		return (write(2, "Error\n", 6), NULL);
	if (Longer_long(argc, argv) == 0)
		return (write(2, "Error\n", 6), NULL);
	len = get_size(argv);
	if (len <= 0)
		return (write(2, "Error\n", 6), NULL);
	data = set_stash(argv);
	if (!data)
		return (NULL);
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
		if (x == 0)
			return (0);
		i++;
		j = 0;
		x = 0;
	}
	return (1);
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
