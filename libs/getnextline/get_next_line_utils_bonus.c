/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:57:46 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/20 20:08:56 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_len_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//proucar o \n
char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;
	char	looking;
	int		i;

	i = 0;
	str = (char *)s;
	looking = (char)c;
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

//copia a string ja alocado na mem e dulica a sobra
char	*ft_strdup_gnl(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//junta a variavel static com o resto da string 
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	newstr = malloc(sizeof(char) * (ft_len_gnl(s1) + ft_len_gnl(s2) + 1));
	if (newstr == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	i;
	char	*result;

	if (!s)
		return (NULL);
	lens = ft_len_gnl(s);
	if (start >= lens)
	{
		result = malloc(sizeof(char) * 1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > lens - start)
		len = lens - start;
	result = malloc (sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}
