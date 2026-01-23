/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:03:01 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/20 11:42:29 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	newstr = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}
/*
#include<stdio.h>
int	main(void)
{
	char s1[] = "duda";
	char s2[] = " seragioli";
	char *new;
	new = ft_strjoin(s1, s2);
	printf("%s\n", new);


	char ss1[] = "";
	char *ne;
	ne = ft_strjoin(ss1, s2);
	printf("Se s1 for vazia: %s\n", ne);
	
	char ss2[] = "";
	char *n;
	n = ft_strjoin(ss1, ss2);
	printf("Se s1 e s2 forem vazias: %s\n", n);
}
*/
