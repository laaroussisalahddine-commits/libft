#include"libft.h"

void ft_memdel(void **ap)
{
    if(ap != NULL && *ap != NULL)
    {
        free(*ap);
        *ap = NULL;
    }
}