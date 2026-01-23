/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:26:37 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/19 15:05:08 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_stack_len(t_stack *head)
{
	int		len;
	t_stack	*curr;
	t_stack	*prev;
	t_stack	*next;

	len = 0;
	prev = NULL;
	curr = head;
	while (curr)
	{
		len++;
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
	}
	return (len);
}

t_stack	*ft_stack_max(t_stack *head)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;
	t_stack	*max;

	prev = NULL;
	curr = head;
	max = head;
	while (curr)
	{
		next = ft_xor(prev, curr->xor);
		if (max->index < curr->index)
			max = curr;
		prev = curr;
		curr = next;
	}
	return (max);
}
