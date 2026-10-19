
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int passed = 0;
static int failed = 0;

static void report(const char *name, int ok)
{
    printf("%s %-35s\n", ok ? "✅ PASS" : "❌ FAIL", name);
    if (ok)
        passed++;
    else
        failed++;
}

/* Test two independent buffers */
static void test_copy(const char *name, const void *src,
    const void *initial, size_t size, size_t n)
{
    unsigned char *mine;
    unsigned char *original;
    void *r1;
    void *r2;
    int ok;

    if (n > size)
    {
        report(name, 0);
        return;
    }
    mine = malloc(size ? size : 1);
    original = malloc(size ? size : 1);
    if (!mine || !original)
    {
        report(name, 0);
        free(mine);
        free(original);
        return;
    }
    memcpy(mine, initial, size);
    memcpy(original, initial, size);

    r1 = ft_memmove(mine, src, n);
    r2 = memmove(original, src, n);

    ok = (r1 == mine && r2 == original);
    ok = ok && memcmp(mine, original, size) == 0;
    report(name, ok);

    free(mine);
    free(original);
}

/* Test overlapping memory */
static void test_overlap(const char *name, const void *initial,
    size_t size, size_t dst, size_t src, size_t n)
{
    unsigned char *mine;
    unsigned char *original;
    void *r1;
    void *r2;
    int ok;

    if (dst > size || src > size
        || n > size - dst || n > size - src)
    {
        report(name, 0);
        return;
    }
    mine = malloc(size ? size : 1);
    original = malloc(size ? size : 1);
    if (!mine || !original)
    {
        report(name, 0);
        free(mine);
        free(original);
        return;
    }
    memcpy(mine, initial, size);
    memcpy(original, initial, size);

    r1 = ft_memmove(mine + dst, mine + src, n);
    r2 = memmove(original + dst, original + src, n);

    ok = (r1 == mine + dst && r2 == original + dst);
    ok = ok && memcmp(mine, original, size) == 0;
    report(name, ok);

    if (!ok)
    {
        size_t i;
        printf("   Expected: ");
        for (i = 0; i < size; i++)
            printf("%02X ", original[i]);
        printf("\n   Got:      ");
        for (i = 0; i < size; i++)
            printf("%02X ", mine[i]);
        printf("\n");
    }
    free(mine);
    free(original);
}

int main(void)
{
    /* 1. NORMAL NON-OVERLAPPING CASES */
    test_copy("Basic copy", "hello", "xxxxx", 5, 5);
    test_copy("Partial copy", "hello", "xxxxx", 5, 3);
    test_copy("One byte", "A", "X", 1, 1);
    test_copy("Two bytes", "AB", "XX", 2, 2);
    test_copy("Full including NULL", "hello", "xxxxxx", 6, 6);
    test_copy("Numbers", "12345", "00000", 5, 5);
    test_copy("Symbols", "!@#$%", "xxxxx", 5, 5);

    /* 2. ZERO LENGTH */
    test_copy("Zero length", "hello", "xxxxx", 5, 0);
    test_copy("Zero empty", "", "", 1, 0);

    /* 3. OVERLAP TO RIGHT: dst > src */
    test_overlap("Right shift by 1", "abcdef", 7, 1, 0, 5);
    test_overlap("Right shift by 2", "abcdef", 7, 2, 0, 4);
    test_overlap("Right shift by 3", "abcdef", 7, 3, 0, 3);
    test_overlap("Right shift including NULL", "abcdef",
        7, 1, 0, 6);
    test_overlap("Right shift 1 byte", "abcdef", 7, 1, 0, 1);
    test_overlap("Right shift n=0", "abcdef", 7, 1, 0, 0);

    /* 4. OVERLAP TO LEFT: dst < src */
    test_overlap("Left shift by 1", "abcdef", 7, 0, 1, 5);
    test_overlap("Left shift by 2", "abcdef", 7, 0, 2, 4);
    test_overlap("Left shift by 3", "abcdef", 7, 0, 3, 3);
    test_overlap("Left shift including NULL", "abcdef",
        7, 0, 1, 6);
    test_overlap("Left shift 1 byte", "abcdef", 7, 0, 1, 1);
    test_overlap("Left shift n=0", "abcdef", 7, 0, 1, 0);

    /* 5. SAME POINTER */
    test_overlap("Same pointer full", "abcdef", 7, 0, 0, 7);
    test_overlap("Same pointer partial", "abcdef", 7, 2, 2, 3);
    test_overlap("Same pointer n=0", "abcdef", 7, 0, 0, 0);

    /* 6. NON-OVERLAP INSIDE SAME BUFFER */
    test_overlap("Separate regions forward", "abcdefghij",
        11, 6, 0, 4);
    test_overlap("Separate regions backward", "abcdefghij",
        11, 0, 6, 4);
    test_overlap("Adjacent regions", "abcdefghij",
        11, 5, 0, 5);

    /* 7. BINARY DATA + EMBEDDED NULL */
    {
        unsigned char data[] = {
            0x00, 0x01, 0x7F, 0x80, 0xFE, 0xFF, 0x42, 0x00
        };
        unsigned char dst[8];

        memset(dst, 0xAA, sizeof(dst));
        test_copy("Binary data full", data, dst, 8, 8);
        test_copy("Binary data partial", data, dst, 8, 5);
        test_overlap("Binary overlap right", data, 8, 2, 0, 6);
        test_overlap("Binary overlap left", data, 8, 0, 2, 6);
        test_overlap("Binary same pointer", data, 8, 0, 0, 8);
    }

    /* 8. POINTER OFFSETS */
    {
        unsigned char data[] = {
            10, 20, 30, 40, 50, 60, 70, 80
        };
        test_overlap("Offset right", data, 8, 3, 1, 4);
        test_overlap("Offset left", data, 8, 1, 3, 4);
        test_overlap("Offset no overlap", data, 8, 5, 0, 3);
        test_overlap("Offset n=0", data, 8, 4, 2, 0);
    }

    /* 9. LONG BUFFERS */
    {
        unsigned char data[10000];
        size_t i;

        for (i = 0; i < sizeof(data); i++)
            data[i] = (unsigned char)(i % 256);

        test_overlap("Long right shift", data,
            10000, 1, 0, 9999);
        test_overlap("Long left shift", data,
            10000, 0, 1, 9999);
        test_overlap("Long middle overlap", data,
            10000, 500, 0, 9000);
        test_overlap("Long same pointer", data,
            10000, 0, 0, 10000);
        test_overlap("Long zero length", data,
            10000, 500, 250, 0);
    }

    /* 10. INTEGER ARRAYS */
    {
        int data[] = {1, 2, 3, 4, 5, 6};
        test_overlap("Integer array right", data,
            sizeof(data), sizeof(int), 0, sizeof(int) * 5);
        test_overlap("Integer array left", data,
            sizeof(data), 0, sizeof(int), sizeof(int) * 5);
    }

    printf("\n====================================\n");
    printf("✅ PASSED: %d\n", passed);
    printf("❌ FAILED: %d\n", failed);
    printf("TOTAL: %d\n", passed + failed);
    printf("====================================\n");

    return (failed != 0);
}
