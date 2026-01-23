/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfputchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:18:55 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/04 19:27:20 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printfputchar(char c)
{
	return (write (1, &c, 1), 1);
}
/*
int	main(void)
{
	printf("%c", ft_printfputchar('a'));
}
*/
