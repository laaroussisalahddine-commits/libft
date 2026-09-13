#include<string.h>

void *ft_memset(void *b, int c, size_t len)
{
    char *str;
    str = (char *) b;

    while(len > 0)
    {
        str[len - 1] = c;
        len--;

    }
    return(str);
}