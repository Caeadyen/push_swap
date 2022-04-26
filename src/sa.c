/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:01:15 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 09:28:32 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	change_prev(t_push_swap *push_swap, t_stack *cur, t_stack *next);
static void	change_next(t_push_swap *push_swap, t_stack *cur, t_stack *next);
static void	set_ends(t_push_swap *push_swap, t_stack *current, t_stack *next);

void	sa(t_push_swap *push_swap)
{
	t_stack	*current;
	t_stack	*next;
	int		acur;

	acur = push_swap->acurrent->index;
	current = push_swap->acurrent;
	if (push_swap->acurrent && push_swap->acurrent->next)
	{
		next = push_swap->acurrent->next;
		change_prev(push_swap, current, next);
		change_next(push_swap, current, next);
		push_swap->acurrent = next;
		commands_push(push_swap, ft_lstnew("sa"));
	}
	else if (push_swap->acurrent && (acur != push_swap->ahead->index))
	{
		next = push_swap->ahead;
		change_prev(push_swap, current, next);
		change_next(push_swap, current, next);
		set_ends(push_swap, current, next);
		commands_push(push_swap, ft_lstnew("sa"));
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
		push_swap->ahead = next;
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
		push_swap->atail = cur;
	}
}

static void	set_ends(t_push_swap *push_swap, t_stack *current, t_stack *next)
{
	push_swap->acurrent = next;
	current->previous = NULL;
	push_swap->ahead = current;
	next->next = NULL;
	push_swap->atail = next;
}
