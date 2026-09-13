#include<unistd.h>
#include<stdlib.h>

int ft_strlen(const char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return(len);
}

char *ft_strdup(const char *s1)
{
    int i;
    char *copy;

    copy = (char *) malloc(ft_strlen(s1) + 1);
    if (!copy)
        return(NULL);
    
    i = 0;
    while(s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = '\0';

    return(copy);
    
}