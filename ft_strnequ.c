#include"libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    size_t i;
    i = 0;
    while( i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    
    if (n == 0 || i == n)
        return(1);
    if (s1[i] - s2[i] == 0)
        return(1);
    return(0);
}