/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:50:23 by hrings            #+#    #+#             */
/*   Updated: 2022/04/22 15:52:51 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_lowest(t_push_swap *push_swap);
static int	find_elment(t_push_swap *push_swap, int limit);
static int	find_ra(t_push_swap *push_swap, int limit);
static int	find_rra(t_push_swap *push_swap, int limit);

void	sortfive(t_push_swap *push_swap)
{
	push_lowest(push_swap);
	sortthree(push_swap);
	while (push_swap->bcurrent)
		pa(push_swap);
}

static void	push_lowest(t_push_swap *push_swap)
{
	int	limit;
	int	moves;

	limit = push_swap->aelements - 3;
	while (push_swap->aelements > 3)
	{
		moves = find_elment(push_swap, limit);
		if (moves < 0)
		{
			while (moves++ < 0)
				rra(push_swap);
		}
		else
		{
			while (moves-- > 0)
				ra(push_swap);
		}
		pb(push_swap);
	}
	if ((push_swap->bcurrent->index != 2) && (push_swap->belements > 1))
		sb(push_swap);
}

static int	find_elment(t_push_swap *push_swap, int limit)
{
	int		result;
	int		min;

	result = find_ra(push_swap, limit);
	min = find_rra(push_swap, limit);
	if (min < result)
		return (min * -1);
	else
		return (result);
}

static int	find_ra(t_push_swap *push_swap, int limit)
{
	int		result;
	t_stack	*current;

	current = push_swap->acurrent;
	result = 0;
	while (current->index > limit)
	{
		if (current->next)
			current = current->next;
		else
			current = push_swap->ahead;
		result++;
	}
	return (result);
}

static int	find_rra(t_push_swap *push_swap, int limit)
{
	int		result;
	t_stack	*current;

	current = push_swap->acurrent;
	result = 0;
	while (current->index > limit)
	{
		if (current->previous)
			current = current->previous;
		else
			current = push_swap->atail;
		result++;
	}
	return (result);
}
