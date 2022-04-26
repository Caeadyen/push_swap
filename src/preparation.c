/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:24:17 by hrings            #+#    #+#             */
/*   Updated: 2022/04/14 17:20:39 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		find_elements_to_push(t_push_swap *push_swap, t_lis *lis);
static t_lis	*ft_lisnew(int index);
static void		ft_lisadd_back(t_lis *lis, int index);
static int		index_in_lis(t_lis *lis, int index);

void	preparation(t_push_swap *push_swap)
{
	t_lis	*lis;
	int		index;
	int		lis_size;

	lis = (t_lis *)malloc(sizeof(t_lis));
	if (!lis)
		exit(1);
	lis->index = 1;
	lis->next = NULL;
	find_elements_to_push(push_swap, lis);
	lis_size = lis_length(lis);
	index = 0;
	while (push_swap->aelements != lis_size)
	{
		if (index_in_lis(lis, push_swap->acurrent->index))
		{
			ra(push_swap);
		}
		else
			pb(push_swap);
		index++;
	}
	free_lis(lis);
}

static void	find_elements_to_push(t_push_swap *push_swap, t_lis *lis)
{
	t_stack	*current;
	int		max_index;

	current = push_swap->ahead;
	while (current->index != 1)
		current = current->next;
	if (current->next)
		current = current->next;
	else
		current = push_swap->ahead;
	max_index = 1;
	while (current->index != push_swap->elements)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			ft_lisadd_back(lis, max_index);
		}
		if (current->next)
			current = current->next;
		else
			current = push_swap->ahead;
	}
	ft_lisadd_back(lis, push_swap->elements);
}

static t_lis	*ft_lisnew(int index)
{
	t_lis	*new_lst;

	new_lst = (t_lis *)malloc(sizeof(t_lis));
	if (!new_lst)
		return (NULL);
	new_lst->index = index;
	new_lst->next = NULL;
	return (new_lst);
}

static void	ft_lisadd_back(t_lis *lis, int index)
{
	t_lis	*item;

	if (!lis)
	{
		lis = ft_lisnew(index);
	}
	else
	{
		item = lis;
		while (item->next)
			item = item->next;
		item->next = ft_lisnew(index);
	}
}

static int	index_in_lis(t_lis *lis, int index)
{
	t_lis	*current;

	if (!lis)
		return (0);
	current = lis;
	while (current)
	{
		if (current->index == index)
			return (1);
		current = current->next;
	}
	return (0);
}
