/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:22:35 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:41:12 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	ss(t_push_swap *push_swap)
{
	if ((push_swap->aelements > 1) && (push_swap->belements > 1))
	{
		ssa(push_swap);
		ssb(push_swap);
	}
}
