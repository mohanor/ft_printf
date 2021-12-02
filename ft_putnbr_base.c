/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:55:18 by matef             #+#    #+#             */
/*   Updated: 2021/12/01 10:55:21 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	int	size_base;
	int	nbr_final[100];
	long long	nb;
	int	i;

	i = 0;
	nb = nbr;
	size_base = 0;
	if (nb < 0)
	{
		nb = -nb;
		*len += ft_putchar('-');
	}
	if (nb == 0)
	{
		*len += ft_putchar('0');
		return ;
	}
	while (base[size_base])
		size_base++;
	while (nb)
	{
		nbr_final[i] = nb % size_base;
		nb = nb / size_base;
		i++;
	}
	while (--i >= 0)
		*len += ft_putchar(base[nbr_final[i]]);
}
