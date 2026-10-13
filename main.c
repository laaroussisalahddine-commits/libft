#include "level0/libft.h"

int main(void)
{
    char *s;

    s = ft_strrchr("hello",'e');
    if (s == NULL)
    {
        printf("NULL\n");
        return 0;
    }    
    printf("%s\n",s);
    return(0);
}