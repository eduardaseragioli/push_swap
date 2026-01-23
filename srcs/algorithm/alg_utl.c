/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:35:26 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/19 19:26:17 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_abso(int cost)
{
	if (cost >= 0)
		return (cost);
	else
		return (cost * -1);
}

void	ft_push_min(t_data *data, t_stack *node)
{
	t_stack	*next_b;
	int		cost_a;
	int		cost_b;

	next_b = ft_next_in_b(data->stack_b, node);
	cost_b = ft_rotate_cost(data->stack_b, next_b);
	cost_a = ft_rotate_cost(data->stack_a, node);
	ft_push_min_whiles_both(data, &cost_a, &cost_b);
	ft_push_min_whiles(data, &cost_a, &cost_b);
	ft_push(&data->stack_a, &data->stack_b, PB);
}

void	ft_push_min_whiles_both(t_data *data, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ft_rotate_both(data);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		ft_reverse_rotate_both(data);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	ft_push_min_whiles(t_data *data, int *cost_a, int *cost_b)
{
	while (*cost_a > 0)
	{
		ft_rotate(&data->stack_a, RA);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		ft_reverse_rotate(&data->stack_a, RRA);
		(*cost_a)++;
	}
	while (*cost_b > 0)
	{
		ft_rotate(&data->stack_b, RB);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		ft_reverse_rotate(&data->stack_b, RRB);
		(*cost_b)++;
	}
}
