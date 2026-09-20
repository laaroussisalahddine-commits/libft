#include"libft.h"

char *ft_strmapi(char const *s ,char (*f) (unsigned int , char))
{
    size_t i;
    char *new;

    new = ft_strnew(ft_strlen(s));
    if(!new)
        return(NULL);
    
    i = 0;
    while(s[i])
    {
        new[i] = f(i,s[i]);
        i++;
    }
    return(new);
}