/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:49:59 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/22 14:12:36 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));
	t_list *c = malloc(sizeof(t_list));

	if (!a || !b || !c)
		return (1);
	
	//a -> next = b;
	//a -> next -> next = c;
	//a -> next -> next -> next = NULL;
	

	a -> next = b;
	b -> next = c;
	c -> next = NULL;

	printf("%d\n", ft_lstsize(a));
	free(a);
	free(b);
	free(c);
}
*/
