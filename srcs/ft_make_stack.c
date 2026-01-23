/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:07:59 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/19 19:38:25 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_data	*ft_make_stack(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->stack_a = NULL;
	data->stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_make_stack_utl(data, argv[i]))
			return (ft_free_data(data), NULL);
		i++;
	}
	return (data);
}

bool	ft_make_stack_utl(t_data *data, char *argv)
{
	int		j;
	char	**nums;

	nums = ft_split(argv, ' ');
	if (nums == NULL)
		return (free(data), false);
	j = 0;
	while (nums[j])
	{
		if (!ft_add_to_stack(&data->stack_a, nums[j]))
		{
			ft_free_split(nums);
			return (false);
		}
		j++;
	}
	ft_free_split(nums);
	return (true);
}
