/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:14:36 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/22 15:00:24 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
/*
#include <stdio.h> 
int	main(void)
{

	t_list a;
	t_list b;
	t_list c;
	t_list d;
	t_list *last_node;

	a.content = (char *)"primeiro nó";

	b.content = (char *)"segundo nó";

	c.content = (char *)"terceiro nó";
	
	d.content = (char *)"chegamos no último nó";

	
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;

	last_node = ft_lstlast(&a);
	
	if (last_node)
		printf("%s\n", (char *)last_node->content);
	return (0);
}
*/
