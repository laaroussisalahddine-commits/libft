#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t total;
    void *s;

    total = nmemb * size;
    s = malloc(total);
    if (!s)
        return(NULL);

    ft_bzero(s,total);
    return(s);
}
