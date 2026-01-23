/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:24:10 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/22 19:36:19 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}
/*
#include <stdio.h>
int	main(void)
{
	char *content_value;
	t_list	*current;

	t_list	*new;
	t_list	a;
	t_list	b;
	t_list	c;
	
	new = ft_lstnew((char *)"arara");
        if (!new)
                return (1);
	

	a.content = (char *)" nó 1";
	b.content = (char *)" nó 2";
	c.content = (char *)" nó 3";
	

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	current = &a;
	
	while (current)
        {
                content_value = (char *)(current->content);
                printf("%s\n", content_value);
                current = current -> next;
        }


	current = &a;

	printf("\n");
	ft_lstadd_back(&current, new);

	while (current)
	{
		content_value = (char *)(current->content);
		printf("%s\n", content_value);
		current = current -> next;
	}
	free(new);
}
*/
