#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strnstr:\n");
    int test_fallido = 0;
    
    struct {
        const char *big;
        const char *little;
        size_t len;
        const char *expected;
    } test_cases[] = {
        {"Foo Bar Baz", "Bar", 4, NULL},
        {"Foo Bar Baz", "Bar", 7, "Bar Baz"},
        {"Hello, World!", "World", 12, "World!"},
        {"Hello, World!", "World", 5, NULL},
        {"abcdef", "def", 6, "def"},
        {"abcdef", "xyz", 6, NULL},
        {"abcdef", "", 6, "abcdef"},
        {"abcdef", "abc", 3, "abcdef"}
    };
    
    for (int i = 0; i < 8; i++) {
        char *obtenido = ft_strnstr(test_cases[i].big, test_cases[i].little, test_cases[i].len);
        printf("Caso %d \"%s\" en \"%s\" con len %zu: Esperado: \"%s\", Obtenido: \"%s\" - ", 
                i+1, test_cases[i].little, test_cases[i].big, test_cases[i].len, 
                test_cases[i].expected ? test_cases[i].expected : "(null)", 
                obtenido ? obtenido : "(null)");
        
        if ((obtenido == NULL && test_cases[i].expected == NULL) || 
            (obtenido && test_cases[i].expected && strcmp(obtenido, test_cases[i].expected) == 0)) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}