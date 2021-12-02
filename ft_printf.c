/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:14:40 by matef             #+#    #+#             */
/*   Updated: 2021/11/28 21:08:03 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char_in(char c)
{
	return (c == 'd' || c == 'u' || c == 'c' || c == 's' || c == 'x'
		|| c == 'X' || c == 'i' || c == 'p');
}

static void	ft_conversions(char c, va_list arguments, int *len)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arguments, int), len);
	if (c == 'u')
		ft_putnbr_unsigned(va_arg(arguments, unsigned int), len);
	if (c == 'c')
		*len += ft_putchar(va_arg(arguments, int));
	if (c == 's')
		ft_putstr(va_arg(arguments, char *), len);
	if (c == 'x' || c == 'X')
		ft_put_x(va_arg(arguments, unsigned int), c, len);
	if (c == 'p')
		ft_address_hex(va_arg(arguments, int *), len);
}

static void	ft_put(const char *str, va_list	arguments, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			*len += ft_putchar(str[i]);
		else
		{
			if (str[i + 1] == '%')
			{
				*len += ft_putchar('%');
				i += 2;
				continue ;
			}
			ft_conversions(str[i + 1], arguments, len);
			i++;
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	char	*ptr;
	int		len;

	len = 0;
	if (!*str)
		return (0);
	va_start (arguments, str);
	ft_put(str, arguments, &len);
	va_end (arguments);
	return (len);
}
