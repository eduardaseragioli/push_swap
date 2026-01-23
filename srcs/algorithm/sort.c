/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:53:55 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/16 14:13:21 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

bool	ft_sorted(t_data *data)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	if (data->stack_b)
		return (false);
	prev = NULL;
	curr = data->stack_a;
	while (curr)
	{
		next = ft_xor(prev, curr->xor);
		if (next && next->index < curr->index)
			return (false);
		prev = curr;
		curr = next;
	}
	return (true);
}

void	ft_sort(t_data *data)
{
	int	len;

	len = ft_stack_len(data->stack_a);
	if (ft_sorted(data))
		return ;
	else if (len == 2)
		ft_swap(&data->stack_a, SA);
	else if (len == 3)
		ft_sort_3(data);
	else if (len == 4)
		ft_sort_4(data);
	else if (len == 5)
		ft_sort_5(data);
	else
		ft_sort_all(data);
}

void	ft_sort_3(t_data *data)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;

	first = data->stack_a;
	middle = first->xor ;
	last = ft_xor(first, middle->xor);
	if (first->index > middle->index && first->index > last->index)
		ft_rotate(&data->stack_a, RA);
	else if (middle->index > first->index && middle->index > last->index)
		ft_reverse_rotate(&data->stack_a, RRA);
	if (data->stack_a->index > data->stack_a->xor->index)
		ft_swap(&data->stack_a, SA);
}

void	ft_sort_4(t_data *data)
{
	t_stack	*min;

	min = ft_get_index_min(data->stack_a);
	while (data->stack_a->index != min->index)
		ft_rotate(&data->stack_a, RA);
	ft_push(&data->stack_a, &data->stack_b, PB);
	ft_sort_3(data);
	ft_push(&data->stack_b, &data->stack_a, PA);
}

void	ft_sort_5(t_data *data)
{
	t_stack	*min;

	min = ft_get_index_min(data->stack_a);
	while (data->stack_a->index != min->index)
		ft_rotate(&data->stack_a, RA);
	ft_push(&data->stack_a, &data->stack_b, PB);
	ft_sort_4(data);
	ft_push(&data->stack_b, &data->stack_a, PA);
}
