#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_itoa:\n");
    int test_fallido = 0;

    const int test_cases[] = {
        1234, 
        -5678, 
        0, 
        42, 
        -1, 
        987654321, 
        -2147483648, 
        2147483647
    };
    
    const char *expected_results[] = {
        "1234",
        "-5678",
        "0",
        "42",
        "-1",
        "987654321",
        "-2147483648",
        "2147483647"
    };
    
    for (int i = 0; i < 8; i++) {
        char *resultado = ft_itoa(test_cases[i]);
        if (resultado != NULL) {
            if (strcmp(resultado, expected_results[i]) != 0) {
                printf("✘ Caso %d FALLA: Esperado \"%s\", Obtenido \"%s\"\n", i + 1, expected_results[i], resultado);
                test_fallido = 1;
            } else {
                printf("✔ Caso %d PASA: Esperado \"%s\", Obtenido \"%s\"\n", i + 1, expected_results[i], resultado);
            }
            free(resultado);
        } else {
            printf("Caso %d: Error en ft_itoa, no se pudo asignar memoria.\n", i + 1);
            test_fallido = 1;
        }
    }
    
    return test_fallido;
}
