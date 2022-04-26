/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:06:04 by hrings            #+#    #+#             */
/*   Updated: 2022/03/09 14:15:14 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_push_swap *push_swap)
{
	if (push_swap->acurrent)
	{
		if (push_swap->acurrent->previous)
			push_swap->acurrent = push_swap->acurrent->previous;
		else
			push_swap->acurrent = push_swap->atail;
	}
	commands_push(push_swap, ft_lstnew("rra"));
}
