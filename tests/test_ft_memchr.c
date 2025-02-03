/* main_ft_memchr.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_memchr:\n");
    int test_fallido = 0;
    
    struct {
        const char data[20];
        int c;
        size_t n;
    } test_cases[] = {
        {"Hola Mundo", 'M', 10},
        {"1234567890", '5', 10},
        {"abcdef", 'z', 6},
        {"Prueba memchr", 'm', 5},
        {"", 'a', 1},
        {"aaaaaa", 'a', 3}
    };
    
    for (int i = 0; i < 6; i++) {
        void *esperado = memchr(test_cases[i].data, test_cases[i].c, test_cases[i].n);
        void *obtenido = ft_memchr(test_cases[i].data, test_cases[i].c, test_cases[i].n);
        printf("Caso %d Buscando '%c' en \"%s\" en los primeros %zu caracteres: Esperado: %p, Obtenido: %p - ", 
               i+1, test_cases[i].c, test_cases[i].data, test_cases[i].n, esperado, obtenido);
        if (esperado == obtenido) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}