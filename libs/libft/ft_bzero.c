/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:46:03 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/14 11:01:11 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
int	main (void)
{
	char	str1[] = "duda";
	char	str2[] = "hello";

	ft_bzero(str1, 2);
	ft_bzero(str2, 5);

	printf("%s\n", str1);
	printf("%s\n", str2);
}
*/
