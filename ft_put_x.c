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
    else{
        ft_put_x(nbr / 16 , c, len);
        ft_put_x(nbr % 16 , c, len);
    }
}