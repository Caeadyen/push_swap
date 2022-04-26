/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:50:22 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 11:58:15 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	init_stack(t_push_swap *push_swap);
static void	init_push_swap(t_push_swap *push_swap);
static int	is_in_order(t_push_swap *push_swap);

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc > 1)
	{
		push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
		if (!push_swap)
			exit(1);
		init_push_swap(push_swap);
		buildstack(argc, argv, push_swap);
		if (push_swap->error_stack)
			error_handle(push_swap);
		init_stack(push_swap);
		read_input(push_swap);
		if (is_in_order(push_swap))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		clean_up(push_swap);
	}
}

static void	init_push_swap(t_push_swap *push_swap)
{
	push_swap->ahead = NULL;
	push_swap->bhead = NULL;
}

static void	init_stack(t_push_swap *push_swap)
{
		push_swap->belements = 0;
		push_swap->elements = push_swap->aelements;
		push_swap->btail = NULL;
		push_swap->acurrent = push_swap->ahead;
		push_swap->bcurrent = push_swap->bhead;
}

static int	is_in_order(t_push_swap *push_swap)
{
	int		index;
	t_stack	*current;

	if (push_swap->bcurrent)
		return (0);
	index = 1;
	current = push_swap->acurrent;
	while (index < push_swap->elements)
	{
		if (current->index != index)
			return (0);
		if (current->next)
			current = current->next;
		else
			current = push_swap->ahead;
		index++;
	}
	return (1);
}
