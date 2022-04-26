/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:46:56 by hrings            #+#    #+#             */
/*   Updated: 2022/04/11 12:23:27 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_push_swap *push_swap)
{
	if (push_swap->acurrent)
	{
		if (push_swap->acurrent->next)
			push_swap->acurrent = push_swap->acurrent->next;
		else
			push_swap->acurrent = push_swap->ahead;
	}
	commands_push(push_swap, ft_lstnew("ra"));
}
