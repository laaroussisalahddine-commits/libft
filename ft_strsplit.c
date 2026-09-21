#include"libft.h"

// count_word;
// count_string;
// skip sep;
//free_string;
// append;

int count_word(char *s,char c)
{
    int i;
    int len;
    len = 0;
    i = 0;

    while(s[i])
    {
        if(s[i] != c)
        {
            while(s[i] && s[i] != c)
            {
                len++;
                i++;
            }
            break;
        }
        i++;
    }
    return(len);
}

int count_string(char const *s, char c)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while(s[i])
    {
        if(s[i] != c)
        {
            count++;
            while(s[i] && s[i] != c)
                i++;
        }
        i++;
    }
    return(count);
}

char *ft_skip(char *s,char c)
{
    int i;

    i = 0;

    while(s[i] && s[i] == c)
        i++;
    
    return(s + i);
}

void free_split(char **arr,int j)
{
    int i;
    i = 0;

    while(i < j)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void ft_append(char **arr, char **current, char c, int j)
{
    int i;
    int len;

    *current = ft_skip(*current, c);
    len = count_word(*current, c);

    arr[j] = ft_strnew(len);
    if (!arr[j])
        return;

    i = 0;
    while (i < len)
    {
        arr[j][i] = (*current)[i];
        i++;
    }

    *current += len;
}
char **ft_strsplit(char const *s, char c)
{
    char **arr;
    char *current;
    int count;
    int j;

    count = count_string(s,c);
    arr = (char **)malloc((count + 1) * (sizeof(char *)));
    if(!arr)
        return(NULL);

    current = (char *)s;
    j = 0;
    while (j < count)
    {
        ft_append(arr,&current,c,j);
        j++;
    }
    arr[j] = NULL;
    return(arr);
}
