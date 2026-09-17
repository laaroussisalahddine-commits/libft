#include "libft.h"

void ft_putstr_fd(char const *s ,int fd)
{
    int i;
    i = 0;

    if (s == NULL)
    {
        ft_putstr_fd("(null)", fd);
        return;
    }
    while(s[i])
    {
        write(fd,&s[i],1);
        i++;
    }
}