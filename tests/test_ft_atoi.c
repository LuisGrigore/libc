/* main_ft_atoi.c */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main() {
    printf("Tests ft_atoi:\n");
    int test_fallido = 0;
    
    const char *test_cases[] = {"42", "-42", "0", "2147483647", "-2147483648", "  123", "\t\n 456", "abc123", "123abc", "  -+42"};
    
    for (int i = 0; i < 10; i++) {
        int esperado = atoi(test_cases[i]);
        int obtenido = ft_atoi(test_cases[i]);
        printf("Caso %d Convirtiendo \"%s\": Esperado: %d, Obtenido: %d - ", i+1, test_cases[i], esperado, obtenido);
        if (esperado == obtenido) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}