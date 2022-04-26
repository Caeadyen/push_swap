/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:29:38 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 13:08:40 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	add_to_stack(t_push_swap *push_swap, int value);

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_lst;

	new_lst = (t_stack *)malloc(sizeof(t_stack));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	new_lst->previous = NULL;
	return (new_lst);
}

void	stack_push(t_push_swap *push_swap, int value)
{
	if (!push_swap->ahead)
	{
		push_swap->ahead = ft_stacknew(value);
		push_swap->ahead->index = 1;
		push_swap->ahead->previous = NULL;
	}
	else
		add_to_stack(push_swap, value);
}

static void	add_to_stack(t_push_swap *push_swap, int value)
{
	int		index;
	t_stack	*previous;
	t_stack	*current;

	index = 1;
	current = push_swap->ahead;
	while (current)
	{
		if (value > current->content)
			index++;
		else if (value < current->content)
			current->index += 1;
		else
			push_swap->error_stack = 1;
		previous = current;
		current = current->next;
	}
	previous->next = (t_stack *)malloc(sizeof(t_stack));
	if (!previous->next)
		error_handle(push_swap);
	previous->next->content = value;
	previous->next->index = index;
	previous->next->next = NULL;
	previous->next->previous = previous;
	push_swap->atail = previous->next;
}

void	buildstack(int n, char **input, t_push_swap *push_swap)
{
	int	index;

	push_swap->error_stack = 0;
	push_swap->ahead = NULL;
	push_swap->aelements = 0;
	index = 1;
	while (index < n)
	{
		stack_push(push_swap, ft_atoi_ps(input[index], push_swap));
		if (push_swap->error_stack)
			break ;
		index++;
		push_swap->aelements += 1;
	}
}
