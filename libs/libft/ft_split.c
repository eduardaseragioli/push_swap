/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:29:23 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/21 12:14:49 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_word(const char *s, char c)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc (sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (s[j] && s[j] != c)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**ft_fill(char **result, const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = ft_word(&s[i], c);
			if (!result[j])
			{
				ft_free(result);
				return (NULL);
			}
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc (sizeof(char *) * (ft_count(s, c) + 1));
	if (words == NULL)
		return (NULL);
	words = ft_fill(words, s, c);
	return (words);
}
/*
#include <stdio.h>
int	main(void)
{
	char s[] = "abc,def,ghi";
	char c = ',';
	char **new;
	int i;

	i= 0;
	new = ft_split(s, c);
	while (new[i])
	{
		printf("%s\n", new[i]);
		i++;
	
	}
	ft_free(new);
}
*/
