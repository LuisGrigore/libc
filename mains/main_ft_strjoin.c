/* main_ft_strjoin.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strjoin:\n");
    int test_fallido = 0;
    
    struct {
        const char *s1;
        const char *s2;
        const char *esperado;
    } test_cases[] = {
        {"Hola", " Mundo", "Hola Mundo"},
        {"", "Test", "Test"},
        {"Concatenar", "", "Concatenar"},
        {"", "", ""},
        {"123", "456", "123456"}
    };
    
    for (int i = 0; i < 5; i++) {
        char *obtenido = ft_strjoin(test_cases[i].s1, test_cases[i].s2);
        printf("Caso %d Concatenando \"%s\" y \"%s\": ", i+1, test_cases[i].s1, test_cases[i].s2);
        
        if (strcmp(obtenido, test_cases[i].esperado) == 0) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: \"%s\", Obtenido: \"%s\")\n", test_cases[i].esperado, obtenido);
            if (test_fallido == 0) test_fallido = i+1;
        }
        
        free(obtenido);
    }
    
    return test_fallido;
}