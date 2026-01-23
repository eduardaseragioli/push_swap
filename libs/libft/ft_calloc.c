/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:02:57 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/22 21:23:22 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		total;

	total = nmemb * size;
	if (size && (total / size != nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, (nmemb * size));
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
    int *ptr = ft_calloc(5, sizeof(int));

    if (!ptr)
        return (1);

    printf("%d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);

    free(ptr);
    return (0);
}
*/
