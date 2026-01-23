/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:36:44 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/22 21:18:10 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del != NULL)
		del(lst->content);
	free(lst);
}
/*
void	delnode(void *content)
{
	free(content);
}

#include <stdio.h>
int	main(void)
{
	t_list *a;
	char *str;

	str = ft_strdup("structs :|");
	if (!str)
		return (1);

	a = ft_lstnew(str);
	if (!a)
	{
		free(str);
		return (1);
	}

       printf("Antes de ft_lstdelone,conteúdo node A: %s\n", (char *)a->content);

	ft_lstdelone(a, delnode);

        printf("Depois de ft_lstdelone, nó liberado");

	return (0);
}
*/
