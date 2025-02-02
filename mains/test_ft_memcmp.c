/* main_ft_memcmp.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_memcmp:\n");
    int test_fallido = 0;
    
    struct {
        const char s1[20];
        const char s2[20];
        size_t n;
    } test_cases[] = {
        {"Hola", "Hola", 4},
        {"Hola", "Holi", 3},
        {"abcdef", "abcdez", 5},
        {"12345", "123", 5},
        {"", "", 1},
        {"abc", "abd", 2}
    };
    
    for (int i = 0; i < 6; i++) {
        int esperado = memcmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        int obtenido = ft_memcmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        printf("Caso %d Comparando \"%s\" y \"%s\" en los primeros %zu caracteres: ", 
               i+1, test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        if ((esperado == 0 && obtenido == 0) || (esperado < 0 && obtenido < 0) || (esperado > 0 && obtenido > 0)) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: %d, Obtenido: %d)\n", esperado, obtenido);
            if (test_fallido == 0) test_fallido = i+1;
        }
    }
    
    return test_fallido;
}