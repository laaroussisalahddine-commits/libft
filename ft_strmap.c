#include"libft.h"

char    *ft_strmap(char const *s, char (*f)(char))
{
    size_t i;
    char *new;

    new = ft_strnew(ft_strlen(s));

    i = 0;
    while(s[i])
    {
        new[i] = f(s[i]);
        i++;
    }
    return(new);
}