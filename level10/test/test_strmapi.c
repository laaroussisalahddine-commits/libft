#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char identity_char(unsigned int i, char c)
{
    (void)i;
    return (c);
}

char to_upper_char(unsigned int i, char c)
{
    (void)i;
    return ((char)ft_toupper((unsigned char)c));
}

char to_lower_char(unsigned int i, char c)
{
    (void)i;
    return ((char)ft_tolower((unsigned char)c));
}

char add_index_char(unsigned int i, char c)
{
    return ((char)(c + i));
}

char replace_x_char(unsigned int i, char c)
{
    (void)i;
    (void)c;
    return ('X');
}

char underscore_space_char(unsigned int i, char c)
{
    (void)i;
    if (c == ' ')
        return ('_');
    return (c);
}

int main(void)
{
    char s1[] = "";
    char s2[] = "a";
    char s3[] = "hElLo 42!";
    char s4[] = "abcd";
    char s5[] = "cat";
    char s6[] = "Libft";
    char s7[] = "a b-c!";
    char s8[] = "12345";
    char s9[] = "HeLLo 42!";
    char *r;

    printf("Test 1 - Empty string:\n");
    r = ft_strmapi(s1, identity_char);
    printf("Expected: \"\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 2 - One character:\n");
    r = ft_strmapi(s2, to_upper_char);
    printf("Expected: \"A\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 3 - Uppercase conversion:\n");
    r = ft_strmapi(s3, to_upper_char);
    printf("Expected: \"HELLO 42!\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 4 - Add index:\n");
    r = ft_strmapi(s4, add_index_char);
    printf("Expected: \"aceg\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 5 - Replace all characters:\n");
    r = ft_strmapi(s5, replace_x_char);
    printf("Expected: \"XXX\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 6 - Original must remain unchanged:\n");
    r = ft_strmapi(s6, to_upper_char);
    printf("Original: \"Libft\" | Got: \"%s\"\n", s6);
    printf("Expected result: \"LIBFT\" | Got: \"%s\"\n\n",
        r ? r : "NULL");
    free(r);

    printf("Test 7 - Spaces and punctuation:\n");
    r = ft_strmapi(s7, underscore_space_char);
    printf("Expected: \"a_b-c!\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 8 - Digits unchanged:\n");
    r = ft_strmapi(s8, to_upper_char);
    printf("Expected: \"12345\" | Got: \"%s\"\n\n", r ? r : "NULL");
    free(r);

    printf("Test 9 - Lowercase conversion:\n");
    r = ft_strmapi(s9, to_lower_char);
    printf("Expected: \"hello 42!\" | Got: \"%s\"\n\n",
        r ? r : "NULL");
    free(r);

    printf("Test 10 - NULL input:\n");
    r = ft_strmapi(NULL, identity_char);
    printf("Expected: NULL | Got: %s\n", r ? r : "NULL");
    free(r);

    return (0);
}