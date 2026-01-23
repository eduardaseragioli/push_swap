/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:22:02 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/21 18:55:06 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_stack	*ft_index_min(t_stack *curr)
{
	t_stack	*next;
	t_stack	*prev;
	t_stack	*min_id;

	min_id = NULL;
	prev = NULL;
	while (curr)
	{
		if (curr->index == -1 && min_id == NULL)
			min_id = curr;
		if (curr->index == -1 && curr->value < min_id->value)
			min_id = curr;
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
	}
	return (min_id);
}

void	ft_index(t_stack *stack)
{
	int		index;
	int		len;
	t_stack	*min_id;

	index = 0;
	len = ft_stack_len(stack);
	while (index < len)
	{
		min_id = ft_index_min(stack);
		min_id->index = index;
		index++;
	}
}

t_stack	*ft_get_index_min(t_stack *curr)
{
	t_stack	*next;
	t_stack	*prev;
	t_stack	*min_id;

	prev = NULL;
	min_id = curr;
	while (curr)
	{
		if (curr->value < min_id->value)
			min_id = curr;
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
	}
	return (min_id);
}

int	ft_find_node(t_stack *head, t_stack *node)
{
	int		i;
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	if (!node)
		return (0);
	prev = NULL;
	curr = head;
	i = 0;
	while (curr && curr != node)
	{
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
		i++;
	}
	return (i);
}
