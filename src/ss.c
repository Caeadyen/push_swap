/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:22:35 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 09:34:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ss(t_push_swap *push_swap)
{
	if ((push_swap->aelements > 1) && (push_swap->belements > 1))
	{
		ssa(push_swap);
		ssb(push_swap);
		commands_push(push_swap, ft_lstnew("ss"));
	}
}
