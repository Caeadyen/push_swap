/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:08:55 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:40:07 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	remove_from_a(t_push_swap *push_swap, t_stack *tmp);
static void	add_to_b(t_push_swap *push_swap, t_stack *tmp);
static void	add_to_empty_b(t_push_swap *push_swap, t_stack *tmp);

void	pb(t_push_swap *push_swap)
{
	t_stack	*tmp;

	if (push_swap->acurrent)
	{
		tmp = push_swap->acurrent;
		if (!tmp->next && !tmp->previous)
		{
			push_swap->ahead = NULL;
			push_swap->atail = NULL;
			push_swap->acurrent = NULL;
		}
		else
			remove_from_a(push_swap, tmp);
		if (!push_swap->bcurrent)
			add_to_empty_b(push_swap, tmp);
		else
			add_to_b(push_swap, tmp);
		push_swap->aelements--;
		push_swap->belements++;
	}
}

static void	remove_from_a(t_push_swap *push_swap, t_stack *tmp)
{
	if (!tmp->previous)
	{
		push_swap->ahead = push_swap->ahead->next;
		push_swap->ahead->previous = NULL;
		push_swap->acurrent = push_swap->ahead;
	}
	else if (!tmp->next)
	{
		push_swap->acurrent = push_swap->ahead;
		push_swap->atail = push_swap->atail->previous;
		push_swap->atail->next = NULL;
	}
	else
	{
		push_swap->acurrent->next->previous = tmp->previous;
		push_swap->acurrent->previous->next = tmp->next;
		push_swap->acurrent = tmp->next;
	}	
}

static void	add_to_b(t_push_swap *push_swap, t_stack *tmp)
{
	if (!push_swap->bcurrent->previous)
	{
		push_swap->bcurrent->previous = tmp;
		push_swap->bhead = tmp;
		push_swap->bhead->next = push_swap->bcurrent;
		push_swap->bcurrent = push_swap->bhead;
		push_swap->bcurrent->previous = NULL;
	}
	else
	{
		tmp->next = push_swap->bcurrent;
		tmp->previous = push_swap->bcurrent->previous;
		push_swap->bcurrent->previous->next = tmp;
		push_swap->bcurrent->previous = tmp;
		push_swap->bcurrent = tmp;
	}
}

static void	add_to_empty_b(t_push_swap *push_swap, t_stack *tmp)
{
	push_swap->bhead = tmp;
	push_swap->bhead->next = NULL;
	push_swap->bhead->previous = NULL;
	push_swap->bcurrent = push_swap->bhead;
	push_swap->btail = push_swap->bhead;
}
