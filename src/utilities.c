/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:25:15 by hrings            #+#    #+#             */
/*   Updated: 2022/04/22 15:12:23 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_atoi_ps(const char *str, t_push_swap *push_swap)
{
	long int	result;
	long int	sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	if (*str < '0' || *str > '9')
		push_swap->error_stack = 1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && result > INT_MIN))
			push_swap->error_stack = 1;
	}
	if ((*str < '0' || *str > '9') && *str)
		push_swap->error_stack = 1;
	return ((int)(result * sign));
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	not_right_pos(t_push_swap *push_swap, t_stack *current, t_stack *tmp)
{
	int	before_index;

	if (current->previous)
		before_index = current->previous->index;
	else
		before_index = push_swap->atail->index;
	if ((current->index > tmp->index) && (before_index < tmp->index))
		return (0);
	else
		return (1);
}

void	copy_struct(t_moves *src, t_moves *dest)
{
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rr = src->rr;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rrr = src->rrr;
	dest->moves = src->moves;
}

int	find_min_move(int a, int b, int c, int d)
{
	int	result;
	int	min;

	min = a;
	result = 1;
	if (b < min)
	{
		min = b;
		result = 2;
	}
	if (c < min)
	{
		min = c;
		result = 3;
	}
	if (d < min)
		result = 4;
	return (result);
}
