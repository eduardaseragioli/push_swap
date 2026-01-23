/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:12:12 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/21 21:05:52 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_rotate_cost(t_stack *head, t_stack *node)
{
	int	id;
	int	len;

	len = ft_stack_len(head);
	id = ft_find_node(head, node);
	if (len / 2 >= id)
		return (id);
	else
		return (-(len - id));
}

t_stack	*ft_next_in_b(t_stack *head, t_stack *node)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;
	t_stack	*temp;

	prev = NULL;
	curr = head;
	temp = NULL;
	while (curr)
	{
		if (curr->index < node->index)
		{
			if (!temp || curr->index > temp->index)
				temp = curr;
		}
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
	}
	if (!temp)
		return (ft_stack_max(head));
	return (temp);
}

t_stack	*ft_get_min(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;
	int		min_cost;
	t_stack	*min_node;

	prev = NULL;
	curr = stack_a;
	min_cost = ft_total_cost(stack_a, stack_b, curr);
	min_node = curr;
	while (curr)
	{
		if (min_cost > ft_total_cost(stack_a, stack_b, curr))
		{
			min_cost = ft_total_cost(stack_a, stack_b, curr);
			min_node = curr;
		}
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
	}
	return (min_node);
}

int	ft_total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node)
{
	int		cost_a;
	int		cost_b;
	t_stack	*temp;

	temp = ft_next_in_b(stack_b, node);
	cost_a = ft_rotate_cost(stack_a, node);
	cost_b = ft_rotate_cost(stack_b, temp);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abso(cost_a) > ft_abso(cost_b))
			return (ft_abso(cost_a));
		else
			return (ft_abso(cost_b));
	}
	return (ft_abso(cost_a) + ft_abso(cost_b));
}

void	ft_sort_all(t_data *data)
{
	t_stack	*temp;
	int		cost_b;

	temp = NULL;
	while (data->stack_a)
	{
		temp = ft_get_min(data->stack_a, data->stack_b);
		ft_push_min(data, temp);
	}
	temp = ft_stack_max(data->stack_b);
	cost_b = ft_rotate_cost(data->stack_b, temp);
	while (cost_b > 0)
	{
		ft_rotate(&data->stack_b, RB);
		cost_b--;
	}
	while (cost_b < 0)
	{
		ft_reverse_rotate(&data->stack_b, RRB);
		cost_b++;
	}
	while (data->stack_b)
		ft_push(&data->stack_b, &data->stack_a, PA);
}
