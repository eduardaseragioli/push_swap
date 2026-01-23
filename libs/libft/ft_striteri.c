/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:28:03 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/17 20:03:26 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
static void test(unsigned int i, char* c)
{
	(void)i;
	*c = *c - 32;
}

#include <stdio.h>
int	main(void)
{
	char text[] = "abcd";
	ft_striteri(text, test);
	printf("%s\n", text);
}
*/
