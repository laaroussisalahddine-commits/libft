#include"libft.h"

void ft_bzero(void *s, size_t n)
{
    char *str;
    str = (char *)s;

    while(n > 0)
    {
        str[n - 1] = 0;
        n--;
    }

}