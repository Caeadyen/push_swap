/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:25:15 by hrings            #+#    #+#             */
/*   Updated: 2022/04/23 10:42:06 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	ft_atoi_ps(const char *str, t_push_swap *push_swap)
{
	long int	result;
	long int	sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	if (*str < '0' || *str > '9')
		push_swap->error_stack = 1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && result > INT_MIN))
			push_swap->error_stack = 1;
	}
	if ((*str < '0' || *str > '9') && *str)
		push_swap->error_stack = 1;
	return ((int)(result * sign));
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
