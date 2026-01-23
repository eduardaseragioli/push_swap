/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:53:07 by eseragio          #+#    #+#             */
/*   Updated: 2025/11/06 11:53:22 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const	char *format, ...);
int	ft_printfputstr(char *s);
int	ft_printfputchar(char c);
int	ft_printfputnbr(int n);
int	ft_printfhexapointer(void *ptr);
int	ft_printfdecimal(unsigned int nb);
int	ft_printfhexacase(unsigned long int nb, int flagcase);

#endif
