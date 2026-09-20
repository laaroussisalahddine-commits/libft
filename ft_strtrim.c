#include"libft.h"

char    *ft_strtrim(char const *s)
{
    size_t start;
    size_t end;
    size_t i;

    char *fresh;

    start = 0;
    while(s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
        start++;
    
    end = ft_strlen(s);

    while((end > start) && (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n'))
        end--;

    fresh = ft_strnew(end - start);
    i = 0;
    while(start < end)
    {
        fresh[i] = s[start];
        i++;
        start++;
    }
    return(fresh);

}