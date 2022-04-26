/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:21:36 by hrings            #+#    #+#             */
/*   Updated: 2022/04/11 13:22:09 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	commands_push(t_push_swap *push_swap, t_list *command)
{
	t_list	*tmp;

	if (push_swap->commands)
	{
		tmp = push_swap->commands;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = command;
	}
	else
		push_swap->commands = command;
}

void	printcommands(t_push_swap *push_swap)
{
	t_list	*tmp;

	tmp = push_swap->commands;
	while (tmp)
	{
		ft_putstr_fd(tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
