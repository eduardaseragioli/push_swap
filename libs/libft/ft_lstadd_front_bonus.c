/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:05:31 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/23 19:03:25 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	t_list  *current;
	char	*node_content_value;

	t_list	a;
	t_list	b;
	t_list	c;
	t_list	new;

	a.content = (char *)"estou no node A(1)";
	
	b.content = (char *)"estou no node B(2)";

	c.content = (char *)"estou no node C(3)";

	new.content = (char *)"estou no node NEW(0)";
	
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	
	current = &a;
	while (current)
	{
		node_content_value = (char *)(current->content);
		printf("%s\n", node_content_value);
		current = current -> next;
	}
	printf("\n");
	current = &a;		

	ft_lstadd_front(&current, &new);
	while (current)
        {
                node_content_value = (char *)(current->content);
                printf("%s\n", node_content_value);
                current = current -> next;
        }
}
*/
