/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:15:06 by hrings            #+#    #+#             */
/*   Updated: 2022/03/10 14:57:15 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rrb(t_push_swap *push_swap)
{
	if (push_swap->bcurrent)
	{
		if (push_swap->bcurrent->previous)
			push_swap->bcurrent = push_swap->bcurrent->previous;
		else
			push_swap->bcurrent = push_swap->btail;
	}
	commands_push(push_swap, ft_lstnew("rrb"));
}
