/* main_ft_isalpha.c */
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main() {
    printf("Tests ft_isalpha:\n");
    int test_fallido = 0;
    
    for (int i = 0; i <= 127; i++) {
        int res_original = isalpha(i);
        int res_mia = ft_isalpha(i);
        printf("Caso %d Caracter '%c': ", i, i);
        if (res_original == res_mia) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: %d, Obtenido: %d)\n", res_original, res_mia);
            if (test_fallido == 0) test_fallido = i;
        }
    }
	
    return test_fallido;
}