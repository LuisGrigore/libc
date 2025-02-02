#include <stdio.h>
#include "libft.h"
#include <string.h>


void test_ft_strtrim(char *s1, char *set, char *expected) {
    char *result = ft_strtrim(s1, set);

    if ((result == NULL && expected == NULL) || (result && expected && strcmp(result, expected) == 0)) {
        printf("✅ Test PASSED: ft_strtrim(\"%s\", \"%s\") -> \"%s\"\n", s1, set, result);
    } else {
        printf("❌ Test FAILED: ft_strtrim(\"%s\", \"%s\") -> \"%s\" (Expected: \"%s\")\n", s1, set, result, expected);
    }

    free(result);
}

int main() {
    // Ejecutar pruebas
    test_ft_strtrim("  hello  ", " ", "hello");
    test_ft_strtrim("xxhelloxx", "x", "hello");
    test_ft_strtrim("hello", "xyz", "hello");
    test_ft_strtrim("", " ", "");
    test_ft_strtrim("hello", "", "hello");
    test_ft_strtrim("xyzxyz", "xyz", "");
    test_ft_strtrim(NULL, "xyz", NULL);
    test_ft_strtrim("  h e l l o  ", " ", "h e l l o");

    return 0;
}
