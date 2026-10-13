#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *new;

    if (start >= ft_strlen(s))
        return(ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;

    new = (char *)malloc(len + 1);
    if (!new)
        return(NULL);
    
    i = 0;
    while(i < len)
    {
        new[i] = s[start];
        i++;
        start++;
    }
    new[i] = 0;
    return(new);
}
