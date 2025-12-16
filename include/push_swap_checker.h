/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:04 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/16 18:04:24 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include<stdlib.h>
# include<unistd.h>
# include<limits.h>

typedef struct s_int_arr
{
	int	*array;
	int	size;
}	t_int_arr;

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

// check if argv is valid, set int* with it's size
// check_argv_a.c
long		ft_atoi(const char *nptr);
int			is_valid(char *c);
int			get_size(char **argv);
int			*set_stash(char **argv);
int			check_dup(int *stash, int len);

// initialize stack with a&b, and it's size
// check_argv_b.c
t_int_arr	*full_check(int argc, char **argv);
int			*ft_intcpy(int *dest, int *src, int n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
t_stack		*set_stack(int argc, char **argv);

//operations_bonus
void		sa(t_stack *stack);
void		ra(t_stack *stack);
void		rra(t_stack *stack);
void		sb(t_stack *stack);
void		rb(t_stack *stack);
void		rrb(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ss(t_stack *stack);
void		rr(t_stack *stack);
void		rrr(t_stack *stack);

//make_checker.c
int			check_sort(t_stack *stack);
int			do_op(char *buffer, t_stack *stack, int i);
int			do_op_2(char *buffer, t_stack *stack, int i);
int			check_buffer(char *buffer, t_stack *stack);

#endif
