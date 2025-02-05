#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "libft.h"

void ft_bzero(void *s, size_t n);

int main() {
    printf("Tests ft_bzero:\n");
    int test_fallido = 0;
    
    struct {
        char input[10];
        size_t n;
    } test_cases[] = {
        {"abcdefghi", 3},
        {"123456789", 5},
        {"xxxxxxxxx", 0},
        {"testing!", 8},
        {"zzzzzzzzz", 10}
    };
    
    for (int i = 0; i < 5; i++) {
        char expected[10];
        memcpy(expected, test_cases[i].input, 10);
        bzero(expected, test_cases[i].n);

        char obtenido[10];
        memcpy(obtenido, test_cases[i].input, 10);
        ft_bzero(obtenido, test_cases[i].n);

        printf("Caso %d \"%s\" con n=%zu:\n", i+1, test_cases[i].input, test_cases[i].n);
        printf("Esperado: \"");
        for (size_t j = 0; j < 10; j++) {
            printf("%c", expected[j] ? expected[j] : '.');
        }
        printf("\"\n");
        
        printf("Obtenido: \"");
        for (size_t j = 0; j < 10; j++) {
            printf("%c", obtenido[j] ? obtenido[j] : '.');
        }
        printf("\"\n");
        
        if (memcmp(expected, obtenido, 10) == 0) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}