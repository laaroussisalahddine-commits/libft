#include"libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *new;

    new = ft_strnew(len);
    if(!new)
        return(NULL);

    i = 0;
    while(i < len)
    {
        new[i] = s[start];
        i++;
        start++;
    }
    return(new);
}