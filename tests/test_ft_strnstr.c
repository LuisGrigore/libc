/* main_ft_strnstr.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strnstr:\n");
    int test_fallido = 0;
    
    const char *big = "Este es un ejemplo de b\u00fasqueda en C";
    
    struct {
        const char *little;
        size_t len;
        const char *esperado;
    } test_cases[] = {
        {"", 30, big},
        {"ejemplo", 30, "ejemplo de b\u00fasqueda en C"},
        {"ejemplo", 10, NULL},
        {"ejemplo", 40, "ejemplo de b\u00fasqueda en C"},
        {"en C", 35, "en C"},
        {"noexiste", 10, NULL},
        {"Este", 10, big}
    };
    
    for (int i = 0; i < 7; i++) {
        const char *little = test_cases[i].little;
        size_t len = test_cases[i].len;
        const char *obtenido = ft_strnstr(big, little, len);
        printf("Caso %d Buscando \"%s\" en \"%s\" con len=%zu: ", i+1, little, big, len);
        printf("Esperado: %s, Obtenido: %s - ", test_cases[i].esperado ? test_cases[i].esperado : "NULL", obtenido ? obtenido : "NULL");
        if ((test_cases[i].esperado == NULL && obtenido == NULL) || (test_cases[i].esperado && obtenido && strcmp(test_cases[i].esperado, obtenido) == 0)) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}
