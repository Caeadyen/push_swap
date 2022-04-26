/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:08:19 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:41:05 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	change_prev(t_push_swap *push_swap, t_stack *cur, t_stack *next);
static void	change_next(t_push_swap *push_swap, t_stack *cur, t_stack *next);
static void	set_ends(t_push_swap *push_swap, t_stack *cur, t_stack *next);

void	sb(t_push_swap *push_swap)
{
	t_stack	*current;
	t_stack	*next;
	int		bcur;

	bcur = push_swap->bcurrent->index;
	current = push_swap->bcurrent;
	if (push_swap->bcurrent && push_swap->bcurrent->next)
	{
		next = push_swap->bcurrent->next;
		change_prev(push_swap, current, next);
		change_next(push_swap, current, next);
		push_swap->bcurrent = next;
	}
	else if (push_swap->bcurrent && (bcur != push_swap->bhead->index))
	{
		next = push_swap->bhead;
		change_prev(push_swap, current, next);
		change_next(push_swap, current, next);
		set_ends(push_swap, current, next);
	}
}

static void	change_prev(t_push_swap *push_swap, t_stack *cur, t_stack *next)
{
	if (cur->previous)
	{
		cur->previous->next = next;
		next->previous = cur->previous;
		cur->previous = next;
	}
	else
	{
		next->previous = NULL;
		cur->previous = next;
		push_swap->bhead = next;
	}
}

static void	change_next(t_push_swap *push_swap, t_stack *cur, t_stack *next)
{
	if (next->next)
	{
		next->next->previous = cur;
		cur->next = next->next;
		next->next = cur;
	}
	else
	{
		cur->next = NULL;
		next->next = cur;
		push_swap->btail = cur;
	}
}

static void	set_ends(t_push_swap *push_swap, t_stack *current, t_stack *next)
{
	push_swap->bcurrent = next;
	current->previous = NULL;
	push_swap->bhead = current;
	next->next = NULL;
	push_swap->btail = next;
}
