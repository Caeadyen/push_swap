/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:22:15 by hrings            #+#    #+#             */
/*   Updated: 2022/04/11 13:31:03 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_ra(t_push_swap *push_swap, t_stack *tmp);
static int	find_rb(t_push_swap *push_swap, t_stack *tmp);
static int	find_rra(t_push_swap *push_swap, t_stack *tmp);
static int	find_rrb(t_push_swap *push_swap, t_stack *tmp);

void	get_moves(t_push_swap *push_swap, t_stack *tmp, t_moves *moves)
{
	int	both;

	moves->ra = find_ra(push_swap, tmp);
	moves->rb = find_rb(push_swap, tmp);
	moves->rra = find_rra(push_swap, tmp);
	moves->rrb = find_rrb(push_swap, tmp);
	both = ft_min(moves->ra, moves->rb);
	moves->ra -= both;
	moves->rb -= both;
	moves->rr = both;
	both = ft_min(moves->rra, moves->rrb);
	moves->rra -= both;
	moves->rrb -= both;
	moves->rrr = both;
	find_min(moves);
}

static int	find_ra(t_push_swap *push_swap, t_stack *tmp)
{
	int		result;
	t_stack	*current;

	current = push_swap->acurrent;
	result = 0;
	while (not_right_pos(push_swap, current, tmp))
	{
		if (current->next)
			current = current->next;
		else
			current = push_swap->ahead;
		result++;
	}
	return (result);
}

static int	find_rb(t_push_swap *push_swap, t_stack *tmp)
{
	int		result;
	t_stack	*current;

	current = push_swap->bcurrent;
	result = 0;
	while (current->index != tmp->index)
	{
		if (current->next)
			current = current->next;
		else
			current = push_swap->bhead;
		result++;
	}
	return (result);
}

static int	find_rra(t_push_swap *push_swap, t_stack *tmp)
{
	int		result;
	t_stack	*current;

	current = push_swap->acurrent;
	result = 0;
	while (not_right_pos(push_swap, current, tmp))
	{
		if (current->previous)
			current = current->previous;
		else
			current = push_swap->atail;
		result++;
	}
	return (result);
}

static int	find_rrb(t_push_swap *push_swap, t_stack *tmp)
{
	int		result;
	t_stack	*current;

	current = push_swap->bcurrent;
	result = 0;
	while (current->index != tmp->index)
	{
		if (current->previous)
			current = current->previous;
		else
			current = push_swap->btail;
		result++;
	}
	return (result);
}
