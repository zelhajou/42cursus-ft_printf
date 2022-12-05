/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:52:23 by zelhajou          #+#    #+#             */
/*   Updated: 2022/12/05 04:24:58 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *format, ...)
{
	va_list argp;
	va_start(argp, format);
	while (*format != '\0') {
		if (*format == '%') {
			format++;
		if (*format == '%') {
			ft_putchr('%');
		} else if (*format == 'c') {
			char char_to_print = va_arg(argp, int);
			ft_putchr(char_to_print);
		}
		} else {
			ft_putchr(*format);
		}
		format++;
	}
	va_end(argp);
}
 
int main(void)
{
	ft_printf("%% %c ", 's');
}