/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexapointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:10:24 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/06 11:59:06 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexaconvertion(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb < 16)
	{
		len++;
		write(1, &"0123456789abcdef"[nb], 1);
	}
	if (nb >= 16)
	{
		len += ft_hexaconvertion(nb / 16);
		len += ft_hexaconvertion(nb % 16);
	}
	return (len);
}

int	ft_printfhexapointer(void *ptr)
{
	int	result;

	result = 0;
	if (ptr == NULL)
		return (ft_printfputstr("(nil)"));
	else
		result += ft_printfputstr("0x");
	result += ft_hexaconvertion((unsigned long int) ptr);
	return (result);
}
/*
int	main (void)
{
        int n = 255;
        int nb = 45;
        int num = 10;

	char *ptr = NULL;

       // printf("\nreturn: %d\n", ft_hexaconvertion(n));

        //printf("\nreturn: %d\n", ft_hexaconvertion(nb));

        //printf("\nreturn: %d\n", ft_hexaconvertion(num));
	printf("\n\n%p \n\n", &ptr);

        printf("\nreturn: %d\n", ft_printfhexapointer(&n));

        printf("\nreturn: %d\n", ft_printfhexapointer(&nb));

        printf("\nreturn: %d\n", ft_printfhexapointer(&num));
}
*/
