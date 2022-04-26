/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:56:25 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:40:44 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	rrr(t_push_swap *push_swap)
{
	if (push_swap->bcurrent)
	{
		if (push_swap->bcurrent->previous)
			push_swap->bcurrent = push_swap->bcurrent->previous;
		else
			push_swap->bcurrent = push_swap->btail;
	}
	if (push_swap->acurrent)
	{
		if (push_swap->acurrent->previous)
			push_swap->acurrent = push_swap->acurrent->previous;
		else
			push_swap->acurrent = push_swap->atail;
	}
}
