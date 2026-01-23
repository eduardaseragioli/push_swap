/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:44:04 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/17 18:26:36 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*result;
	size_t		i;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
static char next(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c+=1;
	else if (c >= 'A' && c <= 'Z')
		c += 1;
	return (c);
}
		
#include <stdio.h>
int	main(void)
{
	char const  text[] = "abc";
	printf("%s\n", ft_strmapi(text, next));
}
*/
