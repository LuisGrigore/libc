/* main_ft_strncmp.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strncmp:\n");
    int test_fallido = 0;
    
    struct {
        const char *s1;
        const char *s2;
        size_t n;
    } test_cases[] = {
        {"Hola", "Hola", 4},
        {"Hola", "Holi", 3},
        {"abcdef", "abcdez", 5},
        {"12345", "123", 5},
        {"", "", 1},
        {"abc", "abd", 2},
        {"aaa", "bbb", 3} // Caso con resultado negativo
    };
    
    for (int i = 0; i < 7; i++) {
        int esperado = strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        int obtenido = ft_strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        printf("Caso %d Comparando \"%s\" y \"%s\" en los primeros %zu caracteres: Esperado: %d, Obtenido: %d - ", 
               i+1, test_cases[i].s1, test_cases[i].s2, test_cases[i].n, esperado, obtenido);
        if ((esperado == 0 && obtenido == 0) || (esperado < 0 && obtenido < 0) || (esperado > 0 && obtenido > 0)) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}
