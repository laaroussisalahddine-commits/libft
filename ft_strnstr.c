#include"libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (needle[0] == '\0')
        return(haystack);
    
    i = 0;
    while(haystack[i] && i < len)
    {
        j = 0;
        while(needle[j] && (i + j) < len && haystack[i + j] == needle[j])
            j++;
        if (needle[j] == '\0')
            return(haystack + i);
        else 
            i++;
    }
    return(0);
}