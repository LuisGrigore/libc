/* main_ft_strlen.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strlen:\n");
    int test_fallido = 0;
    
    const char *test_cases[] = {"", "Hola", "1234567890", "\0hidden", "Muy larga cadena de prueba"};
    size_t esperado, obtenido;
    
    for (int i = 0; i < 5; i++) {
        esperado = strlen(test_cases[i]);
        obtenido = ft_strlen(test_cases[i]);
        printf("Caso %d \"%s\": ", i+1, test_cases[i]);
        if (esperado == obtenido) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: %zu, Obtenido: %zu)\n", esperado, obtenido);
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    printf("\n\n");
    return test_fallido;
}
