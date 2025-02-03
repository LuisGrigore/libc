#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_calloc:\n");
    int test_fallido = 0;
    
    struct {
        size_t nmemb;
        size_t size;
    } test_cases[] = {
        {5, sizeof(int)},
        {10, sizeof(char)},
        {0, sizeof(int)},
        {3, sizeof(double)},
        {100, sizeof(short)}
    };
    
    for (int i = 0; i < 5; i++) {
        void *esperado = calloc(test_cases[i].nmemb, test_cases[i].size);
        void *obtenido = ft_calloc(test_cases[i].nmemb, test_cases[i].size);

        printf("Caso %d Allocando %zu elementos de tamaño %zu: ", i+1, test_cases[i].nmemb, test_cases[i].size);

        if (!esperado || !obtenido) {
            if (esperado == obtenido) {
                printf("✔ PASA (Ambos NULL)\n");
            } else {
                printf("✘ FALLA (Esperado: %p, Obtenido: %p)\n", esperado, obtenido);
                if (test_fallido == 0) test_fallido = i+1;
            }
        } else if (memcmp(esperado, obtenido, test_cases[i].nmemb * test_cases[i].size) == 0) {
            printf("✔ PASA (Esperado: %p, Obtenido: %p)\n", esperado, obtenido);
        } else {
            printf("✘ FALLA (Esperado: %p, Obtenido: %p)\n", esperado, obtenido);
            if (test_fallido == 0) test_fallido = i+1;
        }

        if (esperado) free(esperado);
        if (obtenido) free(obtenido);
    }

    return test_fallido;
}
