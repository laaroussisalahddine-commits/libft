
#include "level0/libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i] && s[i] != (unsigned char )c)
        i++;
    if (s[i] == (char )c)
        return((char *)&s[i]);
    return (NULL);
}
