/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:18:03 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/20 11:02:17 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens)
		return (ft_strdup(""));
	if (len > lens - start)
		len = lens - start;
	result = malloc (sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "paralelepipedo";
	char *result;
	result = ft_substr(str, 3, 4);
	printf("%s\n", result);

	char *new;
	new = ft_substr(str, 20, 4);
	printf("se start for maior que o tamanho de s: %s\n", new);

	char st[] = "";
	result = ft_substr(st, 3, 4);
        printf("se s for vazia, retorna NULL: %s\n", result);

        char *res;
        res = ft_substr(str, 6, 4);
        printf("%s\n", res);
}
*/
