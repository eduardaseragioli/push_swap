/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_stack_utl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:31:08 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/19 15:04:55 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// creat a new node
t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->xor = NULL;
	return (node);
}

t_stack	*ft_stack_last(t_stack *curr)
{
	t_stack	*prev;
	t_stack	*next;

	if (curr == NULL)
		return (NULL);
	prev = NULL;
	while (curr)
	{
		next = ft_xor(curr->xor, prev);
		prev = curr;
		curr = next;
	}
	return (prev);
}

int	ft_stack_addback(t_stack **head, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return (0);
	if (!*head)
	{
		*head = new;
		return (0);
	}
	else
	{
		last = ft_stack_last(*head);
		last->xor = ft_xor(last->xor, new);
		new->xor = last;
	}
	return (1);
}

// duplicated verification
int	ft_is_duplicated(t_stack *head, long value)
{
	t_stack	*curr;
	t_stack	*prev;
	t_stack	*next;

	curr = head;
	prev = NULL;
	while (curr)
	{
		if (curr->value == (int)value)
			return (1);
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
	}
	return (0);
}

int	ft_add_to_stack(t_stack **stack_a, char *str)
{
	long		value;
	t_stack		*new;

	if (!ft_valid_num(str))
		return (ft_putstr_fd("Error\n", 2), 0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ft_is_duplicated(*stack_a, value))
		return (ft_putstr_fd("Error\n", 2), 0);
	new = ft_stack_new((int)value);
	if (new == NULL)
		return (0);
	ft_stack_addback(stack_a, new);
	return (1);
}
