#include"libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
    int i = 0;
    int j = 0;
    
    if (needle[j] == '\0')
        return(haystack);
    
    while(haystack[i])
    {
        j = 0;
        while (needle[j] && haystack[i + j] == needle[j])
            j++;
        if (needle[j] == '\0')
            return(haystack + i);
        else 
            i++;
    }
    return(0);
}

