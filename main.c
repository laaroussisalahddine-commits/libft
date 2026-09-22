#include"libft.h"
#include<stdio.h>

int main(void)
{
    char s1[] = "hello wo";
    char s2[] = "hello wo";
    int x;

    x = ft_strcmp(s1,s2);

    if(x < 0)
        printf("s1 < s2\n");
    else if (x > 0)
        printf("s1 > s2\n");
    else 
        printf("s1 = s2\n");

    return(0);
}