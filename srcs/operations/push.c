/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:29:06 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/16 17:34:49 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*ft_rmv_head(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	prev = *stack;
	if (!prev)
		return (NULL);
	curr = prev->xor;
	if (curr)
	{
		next = ft_xor(prev, curr->xor);
		curr->xor = next;
		if (next)
			prev->xor = NULL;
	}
	*stack = curr;
	return (prev);
}

void	ft_push(t_stack **src, t_stack **dest, char *str)
{
	t_stack	*new_head;
	t_stack	*old_head;

	if (!*src)
		return ;
	new_head = ft_rmv_head(src);
	old_head = *dest;
	new_head->xor = old_head;
	if (old_head)
		old_head->xor = ft_xor(new_head, old_head->xor);
	*dest = new_head;
	if (str)
		ft_putstr_fd(str, 1);
}
