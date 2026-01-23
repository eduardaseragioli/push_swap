/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:38:58 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/29 21:36:04 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenofnum(long n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_lenofnum(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num)
	{
		str[--len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

static int	ft_lenofnum(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n = 42;
	char *result;
	result = ft_itoa(n);
	printf("%s\n", result);

	long num = -2147483650667655890;
	char *res;
	res = ft_itoa(num);
	printf("%s\n", res);

	int mumm = 0;
	char *re;
	re = ft_itoa(mumm);
	printf("%s\n", re);

	int a = 'a';
	char *r;
	r = ft_itoa(a);
	printf("%d\n", a);

	int b = 123456789;
	char *c;
	c = ft_itoa(b);
	printf("%s\n", c);

	int menor = -2147483648;
	char *g;
	g = ft_itoa(menor);
	printf("%s\n", g);	
}
*/
