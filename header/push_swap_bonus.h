/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:52:29 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 11:36:04 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
int		ft_atoi_ps(const char *str, t_push_swap *push_swap);
void	error_handle(t_push_swap *push_swap);
void	clean_up(t_push_swap *push_swap);
void	buildstack(int n, char **input, t_push_swap *push_swap);
void	read_input(t_push_swap *push_swap);

#endif