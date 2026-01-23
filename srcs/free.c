/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:37:47 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/09 16:26:15 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_stack(t_stack *curr)
{
	t_stack	*prev;
	t_stack	*next;

	if (curr == NULL)
		return ;
	prev = NULL;
	while (curr)
	{
		next = ft_xor(prev, curr->xor);
		prev = curr;
		curr = next;
		free(prev);
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->stack_a)
			ft_free_stack(data->stack_a);
		if (data->stack_b)
			ft_free_stack(data->stack_b);
		free(data);
	}
}
