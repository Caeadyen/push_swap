/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:26:53 by hrings            #+#    #+#             */
/*   Updated: 2022/04/14 18:39:33 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	move_one(t_moves *moves, int num);
static void	move_two(t_moves *moves, int num);
static void	move_three(t_moves *moves, int num);
static void	move_four(t_moves *moves, int num);

void	find_min(t_moves *moves)
{
	int	move_op1;
	int	move_op2;
	int	move_op3;
	int	move_op4;
	int	move;

	move_op1 = moves->ra + moves->rb + moves->rr;
	move_op2 = moves->rra + moves->rrb + moves->rrr;
	move_op3 = moves->ra + moves->rrb + moves->rr + moves->rrr;
	move_op4 = moves->rra + moves->rb + moves->rrr + moves->rr;
	move = find_min_move(move_op1, move_op2, move_op3, move_op4);
	if (move == 1)
		move_one(moves, move_op1);
	else if (move == 2)
		move_two(moves, move_op2);
	else if (move == 3)
		move_three(moves, move_op3);
	else if (move == 4)
		move_four(moves, move_op4);
}

static void	move_one(t_moves *moves, int num)
{
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->moves = num;
}

static void	move_two(t_moves *moves, int num)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->moves = num;
}

static void	move_three(t_moves *moves, int num)
{
	moves->ra += moves->rr;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb += moves->rrr;
	moves->rrr = 0;
	moves->moves = num;
}

static void	move_four(t_moves *moves, int num)
{
	moves->ra = 0;
	moves->rb += moves->rr;
	moves->rr = 0;
	moves->rra += moves->rrr;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->moves = num;
}
