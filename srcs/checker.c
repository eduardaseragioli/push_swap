/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:21:45 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/21 17:25:37 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

bool	ft_sort_empty(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	if (stack_a == NULL)
		return (false);
	if (*stack_b != NULL)
		return (false);
	prev = NULL;
	curr = *stack_a;
	while (curr)
	{
		next = ft_xor(prev, curr->xor);
		if (next && next->value < curr->value)
			return (false);
		prev = curr;
		curr = next;
	}
	return (true);
}
/*
void	ft_print_stack(t_stack *stack)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;

	prev = NULL;
	curr = stack;
	while (curr)
	{
		printf("number: %i\tindex: %i\n", curr->value, curr->index);
		next = ft_xor(curr->xor, prev);
		prev = curr;
		curr = next;
	}
}
*/

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (!check_all(stack_a, stack_b, line))
		{
			free(line);
			return ;
		}
		free(line);
	}
	if (ft_sort_empty(stack_a, stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_make_stack(argc, argv);
	if (!data)
		return (1);
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (!stack_a)
		return (ft_printf("Error\n"), 0);
	ft_index(stack_a);
	checker(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	free(data);
	return (0);
}
