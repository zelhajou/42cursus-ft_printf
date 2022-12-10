/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:14:47 by zelhajou          #+#    #+#             */
/*   Updated: 2022/12/10 03:22:53 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long nbr, char c)
{
	if (nbr > 15)
		ft_puthex(nbr / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[nbr % 16], 1);
	else
		write(1, &"0123456789ABCDEF"[nbr % 16], 1);
}