#include"libft.h"

char    *ft_strnew(size_t size)
{
    size_t i;
    char *new;

    new = (char *)malloc(size + 1);
    if (!new)
        return(NULL);
    
    i = 0;
    while(i <= size)
    {
        new[i] = '\0';
        i++;
    }
    return(new);
}
