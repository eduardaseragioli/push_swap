/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:20:08 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/22 11:40:56 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*memory;

	memory = malloc(sizeof(t_list));
	if (memory == NULL)
		return (NULL);
	memory->content = content;
	memory->next = NULL;
	return (memory);
}
/*
#include <stdio.h>
int     main(void)
{
        char *str = "duda";
        t_list *node = ft_lstnew(str);
        if (node == NULL)
                return (1);
        printf("%s\n", (char *)node -> content);
        free (node);
        return (0);
}
*/
