#include "libft.h"

char *ft_strdup(const char *s)
{
    int i;
    char *copy;

    copy = (char *)malloc(ft_strlen(s) + 1);
    if (!copy)
        return(NULL);
    
    i = 0;
    while(s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = 0;
    return(copy);
}