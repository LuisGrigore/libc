/* main_ft_substr.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_substr:\n");
    int test_fallido = 0;
    
    struct {
        const char *s;
        unsigned int start;
        size_t len;
        const char *esperado;
    } test_cases[] = {
        {"Hola Mundo", 0, 4, "Hola"},
        {"Hola Mundo", 5, 5, "Mundo"},
        {"abcdef", 2, 3, "cde"},
        {"1234567890", 7, 10, "890"},
        {"peque\u00f1o", 20, 5, ""},
        {"", 0, 5, ""}
    };
    
    for (int i = 0; i < 6; i++) {
        char *obtenido = ft_substr(test_cases[i].s, test_cases[i].start, test_cases[i].len);
        printf("Caso %d Substring de \"%s\" desde %u con longitud %zu:\n", i+1, test_cases[i].s, test_cases[i].start, test_cases[i].len);
        printf("  Esperado: \"%s\"\n", test_cases[i].esperado);
        printf("  Obtenido: \"%s\"\n", obtenido);
        
        if (strcmp(obtenido, test_cases[i].esperado) == 0) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
        
        free(obtenido);
    }
    
    return test_fallido;
}
