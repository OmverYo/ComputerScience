#include <stdio.h>
#include <string.h> // 표준 함수와 비교용
#include <assert.h>
#include "../src/my_string.h"

void test_strlen()
{
    printf("\n=== Testing my_strlen ===\n");

    const char *test1 = "Hello";
    const char *test2 = "";
    const char *test3 = "A";

    printf("Test 1: \"%s\"\n", test1);
    size_t len1 = my_strlen(test1);
    printf("  my_strlen: %zu, strlen: %zu\n", len1, strlen(test1));
    assert(len1 == strlen(test1));

    printf("Test 2: \"%s\"\n", test2);
    size_t len2 = my_strlen(test2);
    printf("  my_strlen: %zu, strlen: %zu\n", len2, strlen(test2));
    assert(len2 == strlen(test2));

    printf("Test 3: \"%s\"\n", test3);
    size_t len3 = my_strlen(test3);
    printf("  my_strlen: %zu, strlen: %zu\n", len3, strlen(test3));
    assert(len3 == strlen(test3));

    printf("✓ All strlen tests passed!\n");
}

void test_strcpy()
{
    printf("\n=== Testing my_strcpy ===\n");

    char dest1[100] = {0};
    char dest2[100] = {0};
    const char *src = "Hello, World!";

    my_strcpy(dest1, src);
    strcpy(dest2, src);

    printf("Source:    \"%s\"\n", src);
    printf("my_strcpy: \"%s\"\n", dest1);
    printf("strcpy:    \"%s\"\n", dest2);

    assert(strcmp(dest1, dest2) == 0);
    printf("✓ strcpy test passed!\n");
}

void test_strcmp()
{
    printf("\n=== Testing my_strcmp ===\n");

    const char *s1 = "apple";
    const char *s2 = "apple";
    const char *s3 = "banana";
    const char *s4 = "app";

    printf("Compare \"%s\" vs \"%s\"\n", s1, s2);
    int r1 = my_strcmp(s1, s2);
    printf("  my_strcmp: %d, strcmp: %d\n", r1, strcmp(s1, s2));
    assert((r1 == 0) == (strcmp(s1, s2) == 0));

    printf("Compare \"%s\" vs \"%s\"\n", s1, s3);
    int r2 = my_strcmp(s1, s3);
    printf("  my_strcmp: %d, strcmp: %d\n", r2, strcmp(s1, s3));
    assert((r2 < 0) == (strcmp(s1, s3) < 0));

    printf("Compare \"%s\" vs \"%s\"\n", s1, s4);
    int r3 = my_strcmp(s1, s4);
    printf("  my_strcmp: %d, strcmp: %d\n", r3, strcmp(s1, s4));
    assert((r3 > 0) == (strcmp(s1, s4) > 0));

    printf("✓ All strcmp tests passed!\n");
}

void test_strcat()
{
    printf("\n=== Testing my_strcat ===\n");

    char dest1[100] = "Hello, ";
    char dest2[100] = "Hello, ";
    const char *src = "World!";

    my_strcat(dest1, src);
    strcat(dest2, src);

    printf("my_strcat: \"%s\"\n", dest1);
    printf("strcat:    \"%s\"\n", dest2);

    assert(strcmp(dest1, dest2) == 0);
    printf("✓ strcat test passed!\n");
}

int main()
{
    printf("╔════════════════════════════════════╗\n");
    printf("║  String Library Test Suite        ║\n");
    printf("╚════════════════════════════════════╝\n");

    test_strlen();
    test_strcpy();
    test_strcmp();
    test_strcat();

    printf("\n╔════════════════════════════════════╗\n");
    printf("║  ✓ ALL TESTS PASSED!               ║\n");
    printf("╚════════════════════════════════════╝\n");

    return 0;
}