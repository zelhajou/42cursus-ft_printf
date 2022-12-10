/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:03:30 by zelhajou          #+#    #+#             */
/*   Updated: 2022/12/09 23:17:20 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}
