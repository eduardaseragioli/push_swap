/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:41:47 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/16 17:33:16 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*ft_rmv_last(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	prev = NULL;
	curr = *stack;
	if (!curr)
		return (NULL);
	while (curr)
	{
		next = ft_xor(prev, curr->xor);
		if (next == NULL)
			break ;
		prev = curr;
		curr = next;
	}
	if (prev)
		prev->xor = ft_xor(prev->xor, curr);
	curr->xor = NULL;
	return (curr);
}

void	ft_reverse_rotate(t_stack **head, char *str)
{
	t_stack	*old_head;
	t_stack	*new_head;

	if (ft_stack_len(*head) <= 1)
		return ;
	new_head = ft_rmv_last(head);
	old_head = *head;
	new_head->xor = old_head;
	old_head->xor = ft_xor(new_head, old_head->xor);
	*head = new_head;
	if (str)
		ft_putstr_fd(str, 1);
}

void	ft_reverse_rotate_both(t_data *data)
{
	ft_reverse_rotate(&data->stack_a, RRR);
	ft_reverse_rotate(&data->stack_b, "");
}
