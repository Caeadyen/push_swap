/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:46:25 by hrings            #+#    #+#             */
/*   Updated: 2022/04/14 17:22:32 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	lis_length(t_lis *lis)
{
	t_lis	*current;
	int		result;

	current = lis;
	result = 0;
	while (current)
	{
		result++;
		current = current->next;
	}
	return (result);
}

void	free_lis(t_lis *lis)
{
	t_lis	*current;
	t_lis	*previous;

	current = lis;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}
