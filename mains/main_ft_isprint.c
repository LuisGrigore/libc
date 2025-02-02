/* main_ft_isprint.c */
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main() {
    printf("Tests ft_isprint:\n");
    int test_fallido = 0;
    
    for (int i = 0; i <= 127; i++) {
        int res_original = isprint(i);
        int res_mia = ft_isprint(i);
        printf("Caso %d Caracter '%c': ", i, i);
        if ((res_original != 0 && res_mia != 0) || (res_original == 0 && res_mia == 0)) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA (Esperado: %d, Obtenido: %d)\n", res_original, res_mia);
            if (test_fallido == 0) test_fallido = i;
        }
    }
    return test_fallido;
}