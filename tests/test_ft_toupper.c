/* main_ft_tolower.c */
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main() {
    printf("Tests ft_tolower:\n");
    int test_fallido = 0;
    
    for (int i = 0; i <= 127; i++) {
        int res_original = toupper(i);
        int res_mia = ft_toupper(i);
        printf("Caso %d Caracter '%c': ", i, i);
        if (res_original == res_mia) {
            printf("Esperado: %c, Obtenido: %c - ✔ PASA\n", res_original, res_mia);
        } else {
            printf("Esperado: %c, Obtenido: %c - ✘ FALLA\n", res_original, res_mia);
            if (test_fallido == 0) test_fallido = i;
        }
    }
    return test_fallido;
}
