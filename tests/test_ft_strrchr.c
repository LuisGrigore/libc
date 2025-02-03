/* main_ft_strrchr.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strrchr:\n");
    int test_fallido = 0;
    
    struct {
        const char *s;
        int c;
        const char *esperado;
    } test_cases[] = {
        {"Hola Mundo", 'o', "o"},
        {"123412341234", '4', "4"},
        {"abcdef", 'z', NULL},
        {"Prueba strrchr", 'P', "Prueba strrchr"},
        {"", 'a', NULL},
        {"aaaaaa", 'a', "a"},
        {"Hola\0Mundo", 'M', NULL},
        {"Hola\0Mundo", '\0', ""}
    };
    
    for (int i = 0; i < 8; i++) {
        const char *obtenido = ft_strrchr(test_cases[i].s, test_cases[i].c);
        printf("Caso %d Buscando '%c' en \"%s\": ", i+1, test_cases[i].c, test_cases[i].s);
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