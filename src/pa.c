/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:23:59 by hrings            #+#    #+#             */
/*   Updated: 2022/04/11 12:32:21 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	remove_from_b(t_push_swap *push_swap, t_stack *tmp);
static void	add_to_a(t_push_swap *push_swap, t_stack *tmp);
static void	add_to_empty_a(t_push_swap *push_swap, t_stack *tmp);

void	pa(t_push_swap *push_swap)
{
	t_stack	*tmp;

	if (push_swap->bcurrent)
	{
		tmp = push_swap->bcurrent;
		if (!tmp->next && !tmp->previous)
		{
			push_swap->bhead = NULL;
			push_swap->btail = NULL;
			push_swap->bcurrent = NULL;
		}
		else
			remove_from_b(push_swap, tmp);
		if (!push_swap->acurrent)
			add_to_empty_a(push_swap, tmp);
		else
			add_to_a(push_swap, tmp);
		push_swap->aelements++;
		push_swap->belements--;
		commands_push(push_swap, ft_lstnew("pa"));
	}
}

static void	remove_from_b(t_push_swap *push_swap, t_stack *tmp)
{
	if (!tmp->previous)
	{
		push_swap->bhead = push_swap->bhead->next;
		push_swap->bhead->previous = NULL;
		push_swap->bcurrent = push_swap->bhead;
	}
	else if (!tmp->next)
	{
		push_swap->bcurrent = push_swap->bhead;
		push_swap->btail = push_swap->btail->previous;
		push_swap->btail->next = NULL;
	}
	else
	{
		push_swap->bcurrent->next->previous = tmp->previous;
		push_swap->bcurrent->previous->next = tmp->next;
		push_swap->bcurrent = tmp->next;
	}
}

static void	add_to_a(t_push_swap *push_swap, t_stack *tmp)
{
	if (!push_swap->acurrent->previous)
	{
		push_swap->acurrent->previous = tmp;
		push_swap->ahead = tmp;
		push_swap->ahead->next = push_swap->acurrent;
		push_swap->acurrent = push_swap->ahead;
		push_swap->acurrent->previous = NULL;
	}
	else
	{
		tmp->next = push_swap->acurrent;
		tmp->previous = push_swap->acurrent->previous;
		push_swap->acurrent->previous->next = tmp;
		push_swap->acurrent->previous = tmp;
		push_swap->acurrent = tmp;
	}
}

static void	add_to_empty_a(t_push_swap *push_swap, t_stack *tmp)
{
	push_swap->ahead = tmp;
	push_swap->ahead->next = NULL;
	push_swap->ahead->previous = NULL;
	push_swap->atail = push_swap->ahead;
	push_swap->acurrent = push_swap->ahead;
}
