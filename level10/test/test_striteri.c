#include "libft.h"
#include <limits.h>


void change_even(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = 'X';
}

void add_index(unsigned int i, char *c)
{
    *c = *c + i;
}

void to_upper(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper((unsigned char)*c);
}

void only_last(unsigned int i, char *c)
{
    if (i == 4)
        *c = 'Z';
}

void make_empty(unsigned int i, char *c)
{
    if (i == 1)
        *c = '\0';
}

void count_index(unsigned int i, char *c)
{
    *c = '0' + (i % 10);
}

void replace_spaces(unsigned int i, char *c)
{
    (void)i;
    if (*c == ' ')
        *c = '_';
}

void change_first(unsigned int i, char *c)
{
    if (i == 0)
        *c = '!';
}

void identity(unsigned int i, char *c)
{
    (void)i;
    (void)c;
}

void make_lower(unsigned int i, char *c)
{
    (void)i;
    *c = ft_tolower((unsigned char)*c);
}

int main(void)
{
    char s1[] = "";
    char s2[] = "A";
    char s3[] = "abcdef";
    char s4[] = "abcd";
    char s5[] = "hello";
    char s6[] = "abcde";
    char s7[] = "a b  c";
    char s8[] = "Libft 42!";
    char s9[] = "hElLo 42!";
    char s10[] = "12345";

    printf("Test 1 - Empty string:\n");
    ft_striteri(s1, change_even);
    printf("Expected: \"\" | Got: \"%s\"\n\n", s1);

    printf("Test 2 - Single character:\n");
    ft_striteri(s2, change_even);
    printf("Expected: \"X\" | Got: \"%s\"\n\n", s2);

    printf("Test 3 - Even indices:\n");
    ft_striteri(s3, change_even);
    printf("Expected: \"XbXdXf\" | Got: \"%s\"\n\n", s3);

    printf("Test 4 - Add index:\n");
    ft_striteri(s4, add_index);
    printf("Expected: \"aceg\" | Got: \"%s\"\n\n", s4);

    printf("Test 5 - Last character:\n");
    ft_striteri(s5, only_last);
    printf("Expected: \"hellZ\" | Got: \"%s\"\n\n", s5);

    printf("Test 6 - Insert null character:\n");
    ft_striteri(s6, make_empty);
    printf("Expected visible string: \"a\" | Got: \"%s\"\n\n", s6);

    printf("Test 7 - Replace spaces:\n");
    ft_striteri(s7, replace_spaces);
    printf("Expected: \"a_b__c\" | Got: \"%s\"\n\n", s7);

    printf("Test 8 - No modification:\n");
    ft_striteri(s8, identity);
    printf("Expected: \"Libft 42!\" | Got: \"%s\"\n\n", s8);

    printf("Test 9 - Uppercase:\n");
    ft_striteri(s9, to_upper);
    printf("Expected: \"HELLO 42!\" | Got: \"%s\"\n\n", s9);

    printf("Test 10 - NULL arguments:\n");
    ft_striteri(NULL, change_even);
    ft_striteri(s10, NULL);
    printf("Expected: no crash\n");
    printf("String after NULL tests: \"%s\"\n", s10);

    return (0);
}