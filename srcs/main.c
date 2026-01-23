/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:25:33 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/20 19:14:55 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_make_stack(argc, argv);
	if (!data)
		return (1);
	ft_index(data->stack_a);
	ft_sort(data);
	ft_free_data(data);
	return (0);
}
