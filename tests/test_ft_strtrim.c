/* main_ft_strtrim.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strtrim:\n");
    int test_fallido = 0;
    
    struct {
        const char *s1;
        const char *set;
        const char *esperado;
    } test_cases[] = {
        {"  Hola  ", " ", "Hola"},
        {"xxTestxx", "x", "Test"},
		{"TestTestTest", "Test", ""},
		{"TestTest-aaa-TestTest", "Test", "-aaa-"},
		{"TestTest-aaTesta-TestTest", "Test", "-aaTesta-"},
        {"--Trim--", "-", "Trim"},
        {"NoTrim", "xyz", "NoTrim"},
        {"", " ", ""},
        {"     ", " ", ""}
    };
    
    for (int i = 0; i < 6; i++) {
        char *obtenido = ft_strtrim(test_cases[i].s1, test_cases[i].set);
        printf("Caso %d Recortando \"%s\" con \"%s\":\n", i+1, test_cases[i].s1, test_cases[i].set);
        printf("  Esperado: \"%s\"\n", test_cases[i].esperado);
        printf("  Obtenido: \"%s\"\n", obtenido);
        
        if (strcmp(obtenido, test_cases[i].esperado) == 0) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
        
        free(obtenido);
    }
    
    return test_fallido;
}