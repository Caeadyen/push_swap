/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:59:31 by hrings            #+#    #+#             */
/*   Updated: 2022/04/22 15:12:32 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_index(t_push_swap *push_swap, int n);

void	sorttwo(t_push_swap *push_swap)
{
	if (push_swap->acurrent->index > push_swap->acurrent->next->index)
		sa(push_swap);
}

void	sortthree(t_push_swap *push_swap)
{
	int	a;
	int	b;
	int	c;

	a = find_index(push_swap, 0);
	b = find_index(push_swap, 1);
	c = find_index(push_swap, 2);
	if (a > b)
		sa(push_swap);
	if ((c < a) && (c < b))
		rra(push_swap);
	else if ((c < a) || (c < b))
	{
		ra(push_swap);
		sa(push_swap);
		rra(push_swap);
	}
}

static int	find_index(t_push_swap *push_swap, int n)
{
	int		index;
	int		result;
	t_stack	*current;

	index = 0;
	current = push_swap->acurrent;
	result = current->index;
	while (index < n)
	{
		if (current->next)
			current = current->next;
		else
			current = push_swap->ahead;
		result = current->index;
		index++;
	}
	return (result);
}
