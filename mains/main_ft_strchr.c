/* main_ft_strchr.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strchr:\n");
    int test_fallido = 0;
    
    const char *test_cases[] = {"Hola Mundo", "1234567890", "abcdef", "", "aaaaa"};
    char caracteres[] = {'a', '1', 'z', '\0', 'o'};
    
    for (int i = 0; i < 5; i++) {
        char *esperado = strchr(test_cases[i], caracteres[i]);
        char *obtenido = ft_strchr(test_cases[i], caracteres[i]);
        printf("Caso %d Buscando '%c' en \"%s\": ", i+1, caracteres[i], test_cases[i]);
        if (esperado == obtenido) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: %p, Obtenido: %p)\n", (void*)esperado, (void*)obtenido);
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}