/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:10:03 by matef             #+#    #+#             */
/*   Updated: 2021/12/02 20:13:52 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_x(unsigned int nbr, char c, int *len)
{
	char	*base_x;
	char	*base_upperx;

	base_x = "0123456789abcdef";
	base_upperx = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (c == 'x')
			*len += ft_putchar(base_x[nbr]);
		else
			*len += ft_putchar(base_upperx[nbr]);
	}
	else
	{
		ft_put_x(nbr / 16, c, len);
		ft_put_x(nbr % 16, c, len);
	}
}
