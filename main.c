
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int passed = 0;
static int failed = 0;

static void test(const char *name, const char *s, char c,
                 const char **expected, size_t count)
{
    char **result;
    size_t i;
    int ok;

    result = ft_split(s, c);
    ok = (result != NULL);
    i = 0;
    if (ok)
    {
        while (i < count)
        {
            if (!result[i] || strcmp(result[i], expected[i]) != 0)
            {
                ok = 0;
                break;
            }
            i++;
        }
        if (ok && result[count] != NULL)
            ok = 0;
    }

    printf("%s %-30s | separator=%d\n",
        ok ? "✅ PASS" : "❌ FAIL", name, (unsigned char)c);

    if (!ok)
    {
        printf("   Expected: ");
        for (i = 0; i < count; i++)
            printf("[%s] ", expected[i]);
        printf("[NULL]\n   Got: ");

        if (!result)
            printf("NULL");
        else
        {
            for (i = 0; i <= count && result[i]; i++)
                printf("[%s] ", result[i]);
            printf("[NULL]");
        }
        printf("\n");
        failed++;
    }
    else
        passed++;

    if (result)
    {
        i = 0;
        while (result[i])
            free(result[i++]);
        free(result);
    }
}

#define TEST(name, s, c, ...) do {                         \
    const char *e[] = {NULL, __VA_ARGS__};                 \
    test(name, s, c, e + 1,                               \
        sizeof(e) / sizeof(e[0]) - 1);                     \
} while (0)

int main(void)
{
    /* 1. NORMAL CASES */
    TEST("Two words", "hello world", ' ', "hello", "world");
    TEST("Three words", "one two three", ' ',
         "one", "two", "three");
    TEST("Comma", "a,b,c", ',', "a", "b", "c");
    TEST("Single word", "hello", ' ', "hello");
    TEST("No delimiter", "abcdef", ',', "abcdef");
    TEST("Single character", "a", ' ', "a");

    /* 2. EMPTY STRINGS */
    TEST("Empty string", "", ' ');
    TEST("Empty delimiter zero", "", '\0');
    TEST("Only space", " ", ' ');
    TEST("Only spaces", "      ", ' ');
    TEST("Only commas", ",,,,,", ',');
    TEST("Only letters delimiter", "aaaa", 'a');

    /* 3. BOUNDARIES */
    TEST("Leading delimiter", " hello", ' ', "hello");
    TEST("Trailing delimiter", "hello ", ' ', "hello");
    TEST("Both ends", " hello ", ' ', "hello");
    TEST("Multiple leading", "   hello", ' ', "hello");
    TEST("Multiple trailing", "hello   ", ' ', "hello");
    TEST("Multiple both", "   hello   ", ' ', "hello");

    /* 4. CONSECUTIVE DELIMITERS */
    TEST("Double spaces", "hello  world", ' ',
         "hello", "world");
    TEST("Triple commas", "a,,,b", ',', "a", "b");
    TEST("Many commas", ",,a,,b,,c,,", ',',
         "a", "b", "c");
    TEST("Alternating", "a,b,c,d", ',',
         "a", "b", "c", "d");
    TEST("One char words", "a b c", ' ', "a", "b", "c");

    /* 5. DELIMITER CHARACTER */
    TEST("Newline", "a\nb\nc", '\n', "a", "b", "c");
    TEST("Tab", "a\tb\tc", '\t', "a", "b", "c");
    TEST("Pipe", "a|b|c", '|', "a", "b", "c");
    TEST("Digit", "a1b11c", '1', "a", "b", "c");
    TEST("Letter", "hello", 'l', "he", "o");
    TEST("Slash", "/usr/bin/", '/', "usr", "bin");
    TEST("Asterisk", "***a**b***", '*', "a", "b");

    /* 6. NULL DELIMITER */
    TEST("Null delimiter", "hello world", '\0',
         "hello world");
    TEST("Null delimiter single", "A", '\0', "A");
    TEST("Null delimiter spaces", "   ", '\0', "   ");

    /* 7. SPACES PRESERVED */
    TEST("Comma spaces", "a, b, c", ',',
         "a", " b", " c");
    TEST("Tab not space", "a\tb c", ' ', "a\tb", "c");
    TEST("Space not tab", "a b\tc", '\t', "a b", "c");

    /* 8. EMBEDDED NULL */
    TEST("Embedded NULL", "abc\0def", ' ', "abc");
    TEST("Delimiter after NULL", "abc\0,d", ',', "abc");

    /* 9. EDGE CASES */
    TEST("Delimiter beginning", "ahello", 'a', "hello");
    TEST("Delimiter ending", "helloa", 'a', "hello");
    TEST("Repeated characters", "abcabcabc", 'b',
         "a", "ca", "ca", "c");
    TEST("Internal spaces", "hello world,42 school", ',',
         "hello world", "42 school");
    TEST("One char between", ",a,b,c,", ',',
         "a", "b", "c");
    TEST("Different cases", "AaaA", 'a', "A", "A");

    /* 10. LONG WORDS */
    TEST("Long words", "abcdefghij klmnopqrst uvwxyz", ' ',
         "abcdefghij", "klmnopqrst", "uvwxyz");
    TEST("Many tokens", "1,2,3,4,5,6,7,8,9,10", ',',
         "1", "2", "3", "4", "5",
         "6", "7", "8", "9", "10");

    /* 11. MEMORY INDEPENDENCE */
    {
        char s[] = "hello world";
        char **result = ft_split(s, ' ');
        int ok = (result && result[0] && result[1]
            && !result[2]
            && strcmp(result[0], "hello") == 0
            && strcmp(result[1], "world") == 0);

        if (ok)
        {
            s[0] = 'X';
            ok = (strcmp(result[0], "hello") == 0);
            result[0][0] = 'Z';
            ok = ok && s[0] == 'X';
        }

        printf("%s Memory independence\n",
            ok ? "✅ PASS" : "❌ FAIL");
        if (ok)
            passed++;
        else
            failed++;

        if (result)
        {
            size_t i = 0;
            while (result[i])
                free(result[i++]);
            free(result);
        }
    }

    printf("\n====================================\n");
    printf("✅ PASSED: %d\n", passed);
    printf("❌ FAILED: %d\n", failed);
    printf("TOTAL: %d\n", passed + failed);
    printf("====================================\n");
    return (failed != 0);
}
