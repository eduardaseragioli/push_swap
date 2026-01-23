/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:34:49 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/15 16:28:22 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned char text1[] = "eduarda";
	unsigned char c = 'd';
 	char *result;
	result = ft_memchr (text1, c, 5);
	printf("%s\n", result); 
}
*/
