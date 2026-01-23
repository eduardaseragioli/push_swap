/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:23:58 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/23 14:08:24 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (del == NULL || lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current -> next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
/*
static void	delnode(void *content)
{
	free(content);
}

#include <stdio.h> 
int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;
	t_list	*first;

	char *sa;
	char *sb;
	char *sc;
	char *sd;

	sa = ft_strdup("nó A");
	sb = ft_strdup("nó B");
	sc = ft_strdup("nó C");
	sd = ft_strdup("nó D");

	if (!sa || !sb || !sc || !sd)
		return (1);
	
	a = ft_lstnew(sa);
        b = ft_lstnew(sb);
        c = ft_lstnew(sc);
        d = ft_lstnew(sd);

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
	if (!d)
        {
                free(sd);
                return (1);
        }

	a -> next = b;
	b -> next = c;
	c -> next = d;
	d -> next = NULL;
	first = a;

	printf("Antes de ft_lstclear está apontado para A:%p\n", (void *)first);
	printf("conteúdo de A: %s\n", (char *)a->content);
        printf("conteúdo de B: %s\n", (char *)b->content);
        printf("conteúdo de C: %s\n", (char *)c->content);
        printf("conteúdo de D: %s\n", (char *)d->content);

	ft_lstclear(&first, delnode);

        printf("Depois de ft_lstdelone, nó liberado: %p\n", (void *)first);

	return (0);
}
*/
