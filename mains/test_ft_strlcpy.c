/* main_ft_strlcpy.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strlcpy:\n");
    int test_fallido = 0;
    
    char src[] = "Prueba strlcpy";
    char dst1[20], dst2[20];
    size_t ret1, ret2;
    
    ret1 = strlcpy(dst1, src, sizeof(dst1));
    ret2 = ft_strlcpy(dst2, src, sizeof(dst2));
    
    printf("Caso 1 Copia completa: ");
    if (strcmp(dst1, dst2) == 0 && ret1 == ret2) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA (Esperado: %s, Obtenido: %s)\n", dst1, dst2);
        test_fallido = 1;
    }
    
    ret1 = strlcpy(dst1, src, 5);
    ret2 = ft_strlcpy(dst2, src, 5);
    
    printf("Caso 2 Copia truncada: ");
    if (strncmp(dst1, dst2, 5) == 0 && ret1 == ret2) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA (Esperado: %s, Obtenido: %s)\n", dst1, dst2);
        if (test_fallido == 0) test_fallido = 2;
    }
    
    return test_fallido;
}
