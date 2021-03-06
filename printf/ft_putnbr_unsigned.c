/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:53:43 by matef             #+#    #+#             */
/*   Updated: 2021/12/02 20:23:29 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned long nbr, int *len)
{
	char	*base;

	base = "0123456789";
	if (nbr < 10)
	{
		*len += ft_putchar(base[nbr]);
	}
	else
	{
		ft_putnbr_unsigned(nbr / 10, len);
		ft_putnbr_unsigned(nbr % 10, len);
	}
}
