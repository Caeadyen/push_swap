/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:35:08 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 17:20:03 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	execute_command(t_push_swap *push_swap, char *command);
static void	command_error(t_push_swap *push_swap, char *command);

void	read_input(t_push_swap *push_swap)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		execute_command(push_swap, command);
		free(command);
	}
}

static void	execute_command(t_push_swap *push_swap, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		pa(push_swap);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(push_swap);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(push_swap);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(push_swap);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(push_swap);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(push_swap);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(push_swap);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(push_swap);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(push_swap);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(push_swap);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(push_swap);
	else
		command_error(push_swap, command);
}

static void	command_error(t_push_swap *push_swap, char *command)
{
	free(command);
	ft_putstr_fd("Error\n", 1);
	clean_up(push_swap);
	exit(1);
}
