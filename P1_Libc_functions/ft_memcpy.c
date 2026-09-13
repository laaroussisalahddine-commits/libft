#include<string.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    const char *str;
    char *dest;

    str = (const char *)src;
    dest = (char *)dst;
    
    while(n > 0)
    {
        dest[n - 1] = str[n - 1];
        n--;
    }
    return(dest);
}