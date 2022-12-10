/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:52:23 by zelhajou          #+#    #+#             */
/*   Updated: 2022/12/10 03:23:01 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_type(va_list argp, const char *format)
{
	if (*format == '%')
		ft_putchar('%');
	else if (*format == 'c')
		ft_putchar((char)va_arg(argp, int));
	else if (*format == 's')
		ft_putstr(va_arg(argp, char *));
	else if (*format == 'i' || *format == 'd')
		ft_putnbr(va_arg(argp, int));
	else if (*format == 'u')
		ft_putunbr(va_arg(argp, unsigned int));
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(argp, unsigned int), *format);
	else if (*format == 'p')
		ft_putaddr(va_arg(argp, unsigned long));
	else
		ft_putchar(*format);
}

void	ft_printf(const char *format, ...)
{
	va_list	argp;

	va_start(argp, format);
	while (*format != '\0')
	{
		if (*format == '%' && !*(format + 1))
			break;
		if (*format == '%')
		{
			format++;
			check_type(argp, format);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(argp);
}

int	main(void)
{
	int a = 10;
	ft_printf("%p\n", &a);
	printf("%p\n", &a);
}
