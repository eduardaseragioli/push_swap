/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:51:06 by eseragio          #+#    #+#             */
/*   Updated: 2025/10/13 12:10:28 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('6'));
	printf("%d\n", ft_isalnum('h'));
	printf("%d\n", ft_isalnum('\n'));
}
*/
