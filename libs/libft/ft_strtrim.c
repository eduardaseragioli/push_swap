/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:19 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/20 17:35:06 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	if (j < i)
		return (ft_strdup(""));
	return (ft_substr(s1, i, j - i + 1));
}
/*
#include <stdio.h>
int	main(void)
{
	char s1[] = "--hello--";
	char set[] = "--";
	char *new;
	new = ft_strtrim(s1, set);
	printf("%s\n", new);
}
*/
