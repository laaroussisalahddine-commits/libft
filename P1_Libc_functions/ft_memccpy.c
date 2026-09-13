#include<string.h>


void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    const char *str;
    char *dest;
    size_t i;

    str = (const char *)src;
    dest = (char *)dst;
    
    if(n == 0)
        return(NULL);

    i = 0;

    while(i < n)
    {
        dest[i] = str[i];

        if (str[i] == c)
            return(&dest[i + 1]);
        else 
            i++; 
    }
    
    return(NULL);
}