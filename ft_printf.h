/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:44:02 by matef             #+#    #+#             */
/*   Updated: 2021/12/01 10:45:29 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

int     ft_putchar(char c);
void	ft_putnbr(int nb, int *len);
void	ft_putnbr_base(int nbr, char *base, int *len);
void	ft_putnbr_unsigned(unsigned long nbr, int *len);
void	ft_putstr(char *str, int *len);
void	print_address_hex(void *p0);
void	ft_address_hex(void *p0, int *len);
int		ft_printf(const char *str, ...);
void	ft_put_x(unsigned int nbr, char c, int *len);
#endif
