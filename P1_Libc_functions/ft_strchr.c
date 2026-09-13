#include<unistd.h>

char *ft_strchr(const char *s, int c)
{
    int i = 0;

    while(s[i] && s[i] != c)
        i++;

    if (s[i] == c)
        return((char *)&s[i]);

    return(NULL);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char	*result;

// 	result = ft_strchr("salaheddine", 'x');

// 	if (result != NULL)
// 		printf("%s\n", result);
// 	else
// 		printf("Character not found\n");

// 	return (0);
// }