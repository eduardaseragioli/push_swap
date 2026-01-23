/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:09:16 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/23 15:29:21 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst == NULL || f == NULL)
		return ;
	current = lst;
	while (current)
	{
		(*f)(current -> content);
		current = current -> next;
	}
}
/*
static void ft_show_content(void *content)
{
	printf("%s\n", (char *)(content));
}

#include <stdio.h>
int	main(void)
{
	t_list *a;
	t_list *b;
	t_list *c;
        
	t_list *first;
	char *sa;
	char *sb;
	char *sc;

	sa = ft_strdup("nó A");
	sb = ft_strdup("nó B");
	sc = ft_strdup("nó C");
	
	
	if (!sa || !sb || !sc)
		return (1);
	a = ft_lstnew(sa);
	b = ft_lstnew(sb);
	c = ft_lstnew(sc);

	if (!a)
	{
		free(sa);
		return (1);
	}
	if (!b)
	{
		free(sb);
		return (1);
	}
	if (!c)
	{
		free(sc);
		return (1);
	}
	a -> next = b;
	b -> next = c;
	c -> next = NULL;

	first = a;

	ft_lstiter(a, ft_show_content);

}
*/
