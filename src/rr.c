/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:50:46 by hrings            #+#    #+#             */
/*   Updated: 2022/04/11 13:25:22 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rr(t_push_swap *push_swap)
{
	if (push_swap->acurrent && push_swap->bcurrent)
	{
		if (push_swap->acurrent->next)
			push_swap->acurrent = push_swap->acurrent->next;
		else
			push_swap->acurrent = push_swap->ahead;
		if (push_swap->bcurrent->next)
			push_swap->bcurrent = push_swap->bcurrent->next;
		else
			push_swap->bcurrent = push_swap->bhead;
		commands_push(push_swap, ft_lstnew("rr"));
	}
}
