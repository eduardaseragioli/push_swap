/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:31:26 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/23 18:00:47 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	void	*temp;
	t_list	*new_node;
	t_list	*new_list;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	current = lst;
	new_list = NULL;
	while (current)
	{
		temp = (*f)(current -> content);
		new_node = ft_lstnew(temp);
		if (new_node == NULL)
		{
			del(temp);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current = current -> next;
	}
	return (new_list);
}
/*
static void *ft_show_content(void *content)
{
	char *str;
    	char *new;
    	int i;

    	if (!content)
        	return (NULL);

    	str = (char *)content;
    	new = ft_strdup(str); 
    	if (!new)
        	return (NULL);
 	 i = 0;
    	while (new[i])
    	{
        	if (new[i] >= 'a' && new[i] <= 'z')
          	  	new[i] -= 32;
       		i++;
    	}

    return (new);
}

#include <stdio.h>
int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list *first;

	char *sa;
	char *sb;
	char *sc;

	sa = ft_strdup("a");
	sb = ft_strdup("b");
	sc = ft_strdup("c");

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

	printf("Antes");
	first = a;
	while (first)
	{
		printf("Antes: %s\n", (char *)first->content);
		first = first -> next;
	}

	printf("\n Depois");
        first = ft_lstmap(a, ft_show_content, free); 
        while (first)   
        {
                printf("Depois: %s\n", (char *)first->content);
                first = first -> next;
        }
	ft_lstclear(&a, free);
}
*/
