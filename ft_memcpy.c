#include"libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    const unsigned char *str;
    unsigned char *dest;
    size_t i;

    str = (const unsigned char *)src;
    dest = (unsigned char *)dst;
    i = 0;
    while(i < n)
    {
        dest[i] = str[i];
        i++;
    }
    return(dest);
}