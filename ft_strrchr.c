#include "level0/libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;

    i = ft_strlen(s);
    while (i > 0 && s[i] != (unsigned char )c)
        i--;
    if (s[i] == (unsigned char )c)
        return((char *)&s[i]);
    
   return (NULL);
}
