/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:38:53 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/24 09:25:42 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char big[] = "paralelepipedo";
	char little[] = "pipe";
	char litt[] = "rale";
	char lit[] = "da";
	char li[] = " ";

	char *result;
	char *result2;
	char *result3;
	char *result4;
	char *result5;

	result = ft_strnstr(big, little, 15);
	printf("Minha func: %s\n", result);

	result2 = ft_strnstr(big, little, 2);
	printf("%s\n", result2);

	result4 = ft_strnstr(big, litt, 6);
	printf("%s\n", result4);

	result3 =  ft_strnstr(big, lit, 15);
	printf("%s\n", result3);

	result5 = ft_strnstr(big, li , 0);
	printf("%s\n", result5);


}
*/
