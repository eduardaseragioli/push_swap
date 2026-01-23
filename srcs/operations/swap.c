/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:26:30 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/14 10:22:46 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_swap(t_stack **head, char *str)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*fourth;

	if (!*head || ft_stack_len(*head) < 2)
		return ;
	first = ft_rmv_head(head);
	second = *head;
	third = second->xor;
	second->xor = first;
	first->xor = ft_xor(second, third);
	if (third)
	{
		fourth = ft_xor(third->xor, second);
		third->xor = ft_xor(fourth, first);
	}
	*head = second;
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_swap_both(t_data *data)
{
	ft_swap(&data->stack_a, SS);
	ft_swap(&data->stack_b, "");
}
