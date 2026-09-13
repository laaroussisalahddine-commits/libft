#include<string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    i = 0;

    while(i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (i >= n)
        return(0);
    
    return((unsigned char)s1[i] -(unsigned char)s2[i]);
}

#include<stdio.h>
int main(void)
{
    char s1[] = "alah";
    char s2[] = "salah";

    int res;

    res = ft_strncmp(s1,s2,32);
    printf("%d\n",res);
}
