/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:05:57 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/16 12:22:16 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_rotate(t_stack **head, char *str)
{
	t_stack	*first;

	if (*head == NULL)
		return ;
	first = ft_rmv_head(head);
	ft_stack_addback(head, first);
	if (ft_strlen(str))
		ft_putstr_fd(str, 1);
}

void	ft_rotate_both(t_data *data)
{
	ft_rotate(&data->stack_a, RR);
	ft_rotate(&data->stack_b, "");
}
