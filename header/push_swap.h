/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:52:29 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 11:12:50 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN 2147483648

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	moves;
}	t_moves;

typedef struct s_lis
{
	int				index;
	struct s_lis	*next;
}	t_lis;

typedef struct s_push_swap
{
	t_stack	*ahead;
	t_stack	*acurrent;
	t_stack	*atail;
	int		aelements;
	t_stack	*bhead;
	t_stack	*bcurrent;
	t_stack	*btail;
	int		belements;
	t_list	*commands;
	int		elements;
	int		error_stack;
}	t_push_swap;

t_stack	*ft_stacknew(int content);
void	stack_push(t_push_swap *push_swap, int value);
void	pb(t_push_swap *push_swap);
void	pa(t_push_swap *push_swap);
void	ra(t_push_swap *push_swap);
void	rb(t_push_swap *push_swap);
void	rra(t_push_swap *push_swap);
void	rrb(t_push_swap *push_swap);
void	rr(t_push_swap *push_swap);
void	rrr(t_push_swap *push_swap);
void	sa(t_push_swap *push_swap);
void	sb(t_push_swap *push_swap);
void	ss(t_push_swap *push_swap);
void	ssa(t_push_swap *push_swap);
void	ssb(t_push_swap *push_swap);
void	commands_push(t_push_swap *push_swap, t_list *command);
void	printcommands(t_push_swap *push_swap);
int		ft_atoi_ps(const char *str, t_push_swap *push_swap);
void	sortbig(t_push_swap *push_swap);
void	preparation(t_push_swap *push_swap);
void	get_moves(t_push_swap *push_swap, t_stack *tmp, t_moves *moves);
int		not_right_pos(t_push_swap *push_swap, t_stack *current, t_stack *tmp);
int		ft_min(int a, int b);
void	find_min(t_moves *moves);
int		find_min_move(int a, int b, int c, int d);
void	do_moves(t_push_swap *push_swap, t_moves *moves);
void	error_handle(t_push_swap *push_swap);
void	clean_up(t_push_swap *push_swap);
int		lis_length(t_lis *lis);
void	free_lis(t_lis *lis);
void	copy_struct(t_moves *result, t_moves *lowest);
void	buildstack(int n, char **input, t_push_swap *push_swap);
void	sorttwo(t_push_swap *push_swap);
void	sortthree(t_push_swap *push_swap);
void	sortfive(t_push_swap *push_swap);

#endif