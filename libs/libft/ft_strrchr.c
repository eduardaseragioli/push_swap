/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:30:38 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/21 10:42:17 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	looking;
	int		i;

	str = (char *)s;
	looking = (char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == looking)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char text[] = "arara";
	char *result; 
	result = ft_strrchr(text, 'r');
	printf("%s\n", result);

	printf("%s\n", strrchr(text, 'r'));
}
*/
