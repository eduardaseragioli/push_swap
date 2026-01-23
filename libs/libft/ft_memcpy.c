/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:58:14 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/14 21:08:15 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*des;

	i = 0;
	sr = (unsigned char *)src;
	des = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main (void)
{
	char tex1[] = "eduarda";
	char text2[10];
	ft_memcpy(text2, tex1, 3);
	printf("%s\n", text2);
}
*/
