#include "libft.h"

int end_of_string(char *str, char *set)
{
    int i;
    int j;

    i = ft_strlen(str);
    while (i > 0)
    {
        j = 0;
        while (set[j] && str[i] == set[j])
            j++;
        i--;
    }
    return(i);
}

int start_of_string(char *str, char *set)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (set[j] && str[i] == set[j])
            j++;
        i++;
    }
    return(i);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int total;
    int start;
    int end;
    int i;
    char *new;
    
    if (!s1 || !set)
        return (NULL);
    
    start = start_of_string((char *)s1,(char *)set);
    end = end_of_string((char *)s1,(char *)set);
    total = end - start;
    new = (char *)malloc(total + 1);
    if (!new)
        return(NULL);
    i = 0;
    while (start < end)
    {
        new[i] = s1[start];
        i++;
        start++;
    }    
    new[i] = 0;
    return (new);
}

