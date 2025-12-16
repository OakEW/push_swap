/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:12 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 13:58:11 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	int		x;
	long	z;

	i = 0;
	x = 1;
	z = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr [i] == '-' || nptr[i] == '+')
	{
		if (nptr [i] == '-')
			x *= -1;
		i++;
	}
	while ((nptr[i]) <= '9' && (nptr[i]) >= '0')
	{
		z = z * 10 + (nptr[i] - 48);
		i++;
	}
	return (z * x);
}

int	is_valid(char *c)
{
	if (*c <= '9' && *c >= '0'
		&& (*(c + 1) != '-' && *(c + 1) != '+'))
		return (1);
	else if ((*c == '-' || *c == '+')
		&& (*(c + 1) <= '9' && *(c + 1) >= '0'))
		return (0);
	else if (*c <= 32)
		return (0);
	return (-1);
}

int	get_size(char **argv)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (is_valid(&argv[i][j]) == -1)
				return (-1);
			if (is_valid(&argv[i][j]) && !is_valid(&argv[i][j + 1]))
				counter++;
			j++;
		}
		i++;
		j = 0;
	}
	return (counter);
}

int	*set_stash(char **argv)
{
	int		*stash;
	int		i;

	i = -1;
	stash = malloc(sizeof(int) * get_size(argv));
	if (!stash)
		return (NULL);
	while (++argv && *argv != 0)
	{
		while (**argv != 0)
		{
			if (**argv != 0 && **argv > 32)
			{
				if (ft_atoi(*argv) > INT_MAX || ft_atoi(*argv) < INT_MIN)
					return (free (stash), NULL);
				stash[++i] = (int)ft_atoi(*argv);
				while (**argv != 0 && **argv > 32)
					(*argv)++;
			}
			else
				(*argv)++;
		}
	}
	return (stash);
}

int	check_dup(int *stash, int len)
{
	int	i;
	int	j;

	j = len - 1;
	i = 0;
	while (i < j && stash[i] != stash[j])
	{
		i++;
		if (i == j)
		{
			j--;
			i = 0;
		}
	}
	return (j);
}
