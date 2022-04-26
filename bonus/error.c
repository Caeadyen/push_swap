/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:00:53 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:38:32 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	free_stack(t_push_swap *push_swap, char c);

void	error_handle(t_push_swap *push_swap)
{
	ft_putstr_fd("Error\n", 2);
	clean_up(push_swap);
	exit(1);
}

void	clean_up(t_push_swap *push_swap)
{
	if (!push_swap)
		exit(1);
	if (push_swap->ahead)
		free_stack(push_swap, 'a');
	if (push_swap->bhead)
		free_stack(push_swap, 'b');
	free(push_swap);
}

static void	free_stack(t_push_swap *push_swap, char c)
{
	t_stack	*current;
	t_stack	*next;

	if (c == 'a')
	{
		current = push_swap->ahead;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	else if (c == 'b')
	{
		current = push_swap->bhead;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}
