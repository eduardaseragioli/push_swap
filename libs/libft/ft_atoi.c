/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:15:50 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/21 10:39:11 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sing;

	num = 0;
	sing = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr ++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sing *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (num * sing);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", ft_atoi("8"));
	printf("%d\n", ft_atoi("+-8"));
}
*/
