#include<string.h>

size_t ft_strlen(const char *s)
{
    int len = 0;

    while(s[len])
        len++;

    return(len);
}