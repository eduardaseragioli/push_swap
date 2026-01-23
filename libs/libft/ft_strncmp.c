/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:22:43 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/16 21:26:43 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n && (s1[i] && s2[i])) && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
int	main(void)
{
	char text1[] = "abacaxi";
	char text2[] = "abacate";

	printf("%d\n", ft_strncmp(text1, text2, 4));
	printf("%d\n", ft_strncmp(text1, text2, 6));
	printf("%d\n", ft_strncmp("duda", text2, 7));
}
*/
