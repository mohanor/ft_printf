/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:52:00 by matef             #+#    #+#             */
/*   Updated: 2021/12/01 10:52:02 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned long nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		*len += ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_hex(nbr / 16, len);
		ft_putnbr_hex(nbr % 16, len);
	}
}

void	ft_address_hex(void *p0, int *len)
{
	int				i;
	unsigned long	p;

	p = (unsigned long)p0;
	*len += ft_putchar('0');
	*len += ft_putchar('x');
	ft_putnbr_hex(p, len);
}
