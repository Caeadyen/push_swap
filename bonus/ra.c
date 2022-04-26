/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:46:56 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:40:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	ra(t_push_swap *push_swap)
{
	if (push_swap->acurrent)
	{
		if (push_swap->acurrent->next)
			push_swap->acurrent = push_swap->acurrent->next;
		else
			push_swap->acurrent = push_swap->ahead;
	}
}
