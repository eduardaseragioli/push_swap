/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexacase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:32:32 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/05 19:41:00 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfhexacase(unsigned long int nb, int flagcase)
{
	int	len;

	len = 0;
	if (nb < 16)
	{
		len++;
		if (flagcase == 0)
			write(1, &"0123456789abcdef"[nb], 1);
		else if (flagcase == 1)
			write(1, &"0123456789ABCDEF"[nb], 1);
	}
	if (nb >= 16)
	{
		len += ft_printfhexacase(nb / 16, flagcase);
		len += ft_printfhexacase(nb % 16, flagcase);
	}
	return (len);
}
/*
#include <stdio.h>
int main(void)
{
	int n = 255;
	int nb = 45;
	int num = 10;

	printf("\n return: %d\n", ft_printfhexacase(n, 1));
	printf("\n return: %d\n", ft_printfhexacase(n, 0));
	printf("\n return: %d\n", ft_printfhexacase(nb, 1));
	printf("\n return: %d\n", ft_printfhexacase(nb, 0));
	printf("\n return: %d\n", ft_printfhexacase(num, 1));
	printf("\n return: %d\n", ft_printfhexacase(num, 0));

}
*/
