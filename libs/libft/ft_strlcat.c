/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:07 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/16 14:07:01 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && (dest_len + i) < size -1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
int	main(void)
{
	char dest[4] = "ola";
	char src [] = " mundo";
	size_t result;
	result = ft_strlcat(dest, src, 8);
	printf("%zu\n", result);
	printf("Resultado: %s\n", dest);
}
*/
