/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:35 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/06 20:14:26 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_conditions(char type, va_list args)
{
	if (type == 'c')
		return (ft_printfputchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_printfputstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_printfhexapointer(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_printfputnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_printfdecimal(va_arg(args, int)));
	else if (type == 'x')
		return (ft_printfhexacase(va_arg(args, unsigned int), 0));
	else if (type == 'X')
		return (ft_printfhexacase(va_arg(args, unsigned int), 1));
	else if (type == '%')
		return (ft_printfputchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_conditions(format[i], args);
		}
		else
		{
			ft_printfputchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main(void)
{
	char c = 'A';
	char *str = "duda";
	int n = 42;
	void *ptr = &n;
	int nbr = -2345;
	int num = 255; 
	int x = 10;

	int test1;
	int test2;
	int test3;
	int test4;
	int test5;
	int test6;
	int test7;
				
	
	int teste1;
        int teste2;
        int teste3;
        int teste4;
        int teste5;
        int teste6;
        int teste7;

	test1 = ft_printf("CHAR: %c\n", c);
	printf("Retorno ft_printf: %d\n", test1);

	test2 = ft_printf("\nSTRING: %s\n", str);
	printf("Retorno ft_printf: %d\n", test2);

	test3 = ft_printf("\nPOINTER: %p\n", ptr);
	printf("Retorno ft_printf: %d\n", test3);

	test4 = ft_printf("\nDECIMAL: %d\n", nbr);
	printf("Retorno ft_printf: %d\n", test4);

	test5 = ft_printf("\n%u\n", num);
	printf("Retorno ft_printf: %d\n", test5);

	test6 = ft_printf("\nLOWER: %x\n", x);
	printf("Retorno ft_printf: %d\n", test6);

	test7 = ft_printf("\nUPPER: %X\n", x);
	printf("Retorno ft_printf: %d\n", test7);


	printf("\n\nPRINTF ORIGINAL\n\n");
	
	teste1 = printf("CHAR: %c\n", c);
	printf("Retorno ft_printf: %d\n", teste1);

        teste2 = printf("\nSTRING: %s\n", str);
	printf("Retorno ft_printf: %d\n", teste2);

        teste3 = printf("\nPOINTER: %p\n", ptr);
	printf("Retorno ft_printf: %d\n", teste3);

        teste4 = printf("\nDECIMAL: %d\n", nbr);
	printf("Retorno ft_printf: %d\n", teste4);

        teste5 = printf("\n%u\n", num);
	printf("Retorno ft_printf: %d\n", teste5);

        teste6 = printf("\nLOWER: %x\n", x);
	printf("Retorno ft_printf: %d\n", teste6);

        teste7 = printf("\nUPPER: %X\n", x);
	printf("Retorno ft_printf: %d\n", teste7);

}
*/
