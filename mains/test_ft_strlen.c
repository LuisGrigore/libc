/* main_ft_strlen.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strlen:\n");
    int test_fallido = 0;
    
    const char *test_cases[] = {"", "Hola", "1234567890", "(hidden)\0hidden", "Muy larga cadena de prueba"};
    size_t esperado, obtenido;
    
    for (int i = 0; i < 5; i++) {
        esperado = strlen(test_cases[i]);
        obtenido = ft_strlen(test_cases[i]);
        printf("Caso %d \"%s\": Esperado: %zu, Obtenido: %zu - ", i+1, test_cases[i], esperado, obtenido);
        if (esperado == obtenido) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}
