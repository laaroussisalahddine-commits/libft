#include "libft.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return(1);
    char *str = av[1];
    char *set = av[2];
    char *new;
    new = ft_strtrim(str, set);
    printf("%s\n",new);
    free(new);
    return(0);
}