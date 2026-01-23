/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfputnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:36:03 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/05 13:57:52 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfputnbr(int n)
{
	int			len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_printfputchar('-');
		nb *= -1;
	}
	if (nb > 9)
		len += ft_printfputnbr(nb / 10);
	len += ft_printfputchar(nb % 10 + '0');
	return (len);
}
/*
int	main(void)
{
	int a;
	a = ft_printfputnbr(2345566);
}

*/
