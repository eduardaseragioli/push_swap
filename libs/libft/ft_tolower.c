/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:58:50 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/13 14:13:11 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_tolower('b'));
	printf("%d\n", ft_tolower('B'));
	printf("%d\n", ft_tolower('9'));
}
*/
