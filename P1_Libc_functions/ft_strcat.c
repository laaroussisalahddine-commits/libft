
char *ft_strcat(char *s1, const char *s2)
{
    int is1;
    int js2;
    
    js2 = 0;
    is1 = 0;

    while(s1[is1])
        is1++;
    
    while(s2[js2])
    {
        s1[is1] = s2[js2];
        is1++;
        js2++;
    }
    s1[is1] = '\0';

    return(s1);
}