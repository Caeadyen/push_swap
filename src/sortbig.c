/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:19:19 by hrings            #+#    #+#             */
/*   Updated: 2022/04/08 11:34:23 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		insert_int_a(t_push_swap *push_swap);
static t_moves	*find_best_moves(t_push_swap *push_swap);
static int		find_lowest_top(t_push_swap *push_swap);
static void		find_lowest(t_push_swap *push_swap, t_moves *re, t_moves *low);

void	sortbig(t_push_swap *push_swap)
{
	int	lowest_top;

	while (push_swap->bcurrent)
	{
		insert_int_a(push_swap);
	}
	lowest_top = find_lowest_top(push_swap);
	if (lowest_top < 0)
	{
		while (lowest_top++ < 0)
			rra(push_swap);
	}
	else if (lowest_top > 0)
	{
		while (lowest_top-- > 0)
			ra(push_swap);
	}
}

static int	find_lowest_top(t_push_swap *push_swap)
{
	int		result;
	t_stack	*tmp;

	tmp = push_swap->acurrent;
	result = 0;
	while (tmp->index != 1)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = push_swap->ahead;
		result++;
	}
	if (result > push_swap->elements / 2)
		return (result - push_swap->elements);
	else
		return (result);
}

static void	insert_int_a(t_push_swap *push_swap)
{
	t_moves	*moves;

	moves = find_best_moves(push_swap);
	do_moves(push_swap, moves);
	free(moves);
}

static t_moves	*find_best_moves(t_push_swap *push_swap)
{
	t_moves	*result;
	t_moves	*lowest;

	result = (t_moves *)malloc(sizeof(t_moves));
	if (!result)
		error_handle(push_swap);
	lowest = (t_moves *)malloc(sizeof(t_moves));
	if (!lowest)
		error_handle(push_swap);
	lowest->moves = push_swap->elements * 3;
	find_lowest(push_swap, result, lowest);
	free(result);
	return (lowest);
}

static void	find_lowest(t_push_swap *push_swap, t_moves *re, t_moves *low)
{
	t_stack	*tmp;

	tmp = push_swap->bhead;
	while (tmp)
	{
		get_moves(push_swap, tmp, re);
		if (re->moves < low->moves)
		{
			if (re->moves == 0)
			{
				copy_struct(re, low);
				break ;
			}
			copy_struct(re, low);
		}		
		tmp = tmp->next;
	}
}
