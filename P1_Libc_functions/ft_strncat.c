#include<string.h>

char *ft_strncat(char *s1, const char *s2, size_t n)
{
    size_t is1 = 0;
    size_t js2 = 0;

    while(s1[is1])
        is1++;

    while(s2[js2] && js2 < n)
    {
        s1[is1] = s2[js2];
        is1++;
        js2++;
    }

    s1[is1] = '\0';
    return(s1);

}