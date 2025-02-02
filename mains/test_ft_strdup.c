/* main_ft_strdup.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int main() {
    printf("Tests ft_strdup:\n");
    int test_fallido = 0;
    
    const char *test_cases[] = {"Hola", "", "1234567890", "abcdef", "Muy larga cadena de prueba"};
    
    for (int i = 0; i < 5; i++) {
        char *esperado = strdup(test_cases[i]);
        char *obtenido = ft_strdup(test_cases[i]);
        printf("Caso %d Duplicando \"%s\": ", i+1, test_cases[i]);
        if (strcmp(esperado, obtenido) == 0) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: %s, Obtenido: %s)\n", esperado, obtenido);
            if (test_fallido == 0) test_fallido = i+1;
        }
        free(esperado);
        free(obtenido);
    }
    
    return test_fallido;
}
