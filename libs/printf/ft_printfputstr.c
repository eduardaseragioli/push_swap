/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfputstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:27:57 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/04 19:34:20 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfputstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6), 6);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char *str;
	str = "duda";
	printf("%s", str);
}
*/
