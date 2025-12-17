/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:04 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/17 13:23:33 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int	*in_b;
	int	*in_a;
}	t_stack;

// check if argv is valid, set int* with it's size
// check_argv_a.c
long		ft_atoi(const char *nptr);
int			is_valid(char *c);
int			get_size(char **argv);
int			*set_stash(char **argv);
int			check_dup(int *stash, int len);

// check_argv_b.c
t_int_arr	*full_check(int argc, char **argv);
int			check_emt(int argc, char **argv);
int			*ft_intcpy(int *dest, int *src, int n);
void		*ft_calloc(size_t nmemb, size_t size);

// initialize stack with a&b, it's size and target
//set_stack.c
t_stack		*set_stack(int argc, char **argv);
void		find_index(t_stack *stack);
void		get_in_b(int x, t_stack *stack);
void		get_in_a(int x, t_stack *stack);

//operations
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

//cal_cost.c
int			cal_cost(int index, t_stack *stack, char flag);
int			locate_cheapest(t_stack *stack, char flag);
int			ft_abs(int i);

//make_move.c
void		smart_roll(t_stack *stack, int flag_a, int flag_b);
void		make_move_b(t_stack *stack, char flag);
void		make_move_a(t_stack *stack, char flag);

//pushswap.c
void		sort_three(t_stack *stack);
void		fin_roll(t_stack *stack);
void		push_swap(t_stack *stack);

#endif
