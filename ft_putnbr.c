#include "libft.h"

void ft_putnbr(int n)
{
    long nb;
    nb = n;

    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }

    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}