/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:50:22 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:53:17 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sorting(t_push_swap *push_swap);
static void	init_stack(t_push_swap *push_swap);
static void	init_push_swap(t_push_swap *push_swap);

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
		sorting(push_swap);
		printcommands(push_swap);
		clean_up(push_swap);
	}
}

static void	sorting(t_push_swap *push_swap)
{
	if (push_swap->elements > 5)
	{
		preparation(push_swap);
		sortbig(push_swap);
	}
	else if (push_swap->elements > 3)
		sortfive(push_swap);
	else if (push_swap->elements == 3)
		sortthree(push_swap);
	else if (push_swap->elements == 2)
		sorttwo(push_swap);
}

static void	init_push_swap(t_push_swap *push_swap)
{
	push_swap->ahead = NULL;
	push_swap->bhead = NULL;
	push_swap->commands = NULL;
}

static void	init_stack(t_push_swap *push_swap)
{
		push_swap->belements = 0;
		push_swap->elements = push_swap->aelements;
		push_swap->btail = NULL;
		push_swap->acurrent = push_swap->ahead;
		push_swap->bcurrent = push_swap->bhead;
}
