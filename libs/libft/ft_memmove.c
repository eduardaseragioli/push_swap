/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:21:40 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/15 14:45:45 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*des;

	sr = (unsigned char *)src;
	des = (unsigned char *)dest;
	if ((!dest && !src) || n == 0)
		return (dest);
	if (des > sr)
	{
		while (n > 0)
		{
			n--;
			des[n] = sr[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned char text1[] = "eduarda";
	ft_memmove(text1 + 2, text1, 5);
	printf("%s\n", text1);
}
*/
