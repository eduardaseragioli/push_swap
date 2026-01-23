/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:49:14 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/21 14:59:48 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	ft_strcmp(char *s1, char *s2);
static int	instruct_utils(t_stack **stack_a, t_stack **stack_b, char *line);

int	check_instruct(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_swap(stack_a, "");
	else if (!ft_strcmp(line, "sb\n"))
		ft_swap(stack_b, "");
	else if (!ft_strcmp(line, "ss\n"))
	{
		ft_swap(stack_a, "");
		ft_swap(stack_b, "");
	}
	else if (!ft_strcmp(line, "ra\n"))
		ft_rotate(stack_a, "");
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate(stack_b, "");
	else
		return (instruct_utils(stack_a, stack_b, line));
	return (1);
}

static int	instruct_utils(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotate(stack_a, "");
		ft_rotate(stack_b, "");
	}
	else if (!ft_strcmp(line, "pa\n"))
		ft_push(stack_b, stack_a, "");
	else if (!ft_strcmp(line, "pb\n"))
		ft_push(stack_a, stack_b, "");
	else if (!ft_strcmp(line, "rra\n"))
		ft_reverse_rotate(stack_a, "");
	else if (!ft_strcmp(line, "rrb\n"))
		ft_reverse_rotate(stack_b, "");
	else if (!ft_strcmp(line, "rrr\n"))
	{
		ft_reverse_rotate(stack_a, "");
		ft_reverse_rotate(stack_b, "");
	}
	else
		return (0);
	return (1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	check_all(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (check_instruct(stack_a, stack_b, line))
		return (1);
	return (ft_putendl_fd("Error", 2), 0);
}
