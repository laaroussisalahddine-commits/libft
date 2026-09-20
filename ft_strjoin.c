#include"libft.h"

char    *t_strjoin(char const *s1, char const*s2)
{
    size_t i;
    size_t j;
    size_t lenf;
    char *fresh;

    lenf = ft_strlen(s1) + ft_strlen(s2);
    fresh = ft_strnew(lenf);

    i = 0;
    while(s1[i])
    {
        fresh[i] = s1[i];
        i++;
    }

    j = 0;
    while(s2[j])
    {
        fresh[i] = s2[j];
        i++;
        j++;
    }
    return(fresh);
}