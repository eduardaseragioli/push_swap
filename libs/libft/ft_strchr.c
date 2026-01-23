/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:14:13 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/16 19:21:47 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	looking;
	size_t	i;

	str = (char *)s;
	looking = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == looking)
			return (&str[i]);
		i++;
	}
	if (looking == '\0')
		return (&str[i]);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "arara";
	char *ptr;
	
	printf("%s\n", strchr(str, 'u'));
	ptr = ft_strchr(str, 'r');
	printf("%s\n", ptr);
}
*/
