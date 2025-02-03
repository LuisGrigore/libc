/* main_ft_strlcpy.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_strlcpy:\n");
    int test_fallido = 0;
    
    char src[] = "Prueba strlcpy";
	printf("Texto de prueba: \"Prueba strlcpy\".\n");
    char dst1[20], dst2[20];
    size_t ret1, ret2;
    
    ret1 = strlcpy(dst1, src, sizeof(dst1));
    ret2 = ft_strlcpy(dst2, src, sizeof(dst2));
    
    printf("Caso 1 Copia completa: \n");
    printf("  Esperado: \"%s\" (Dir: %p), Obtenido: \"%s\" (Dir: %p)\n", dst1, (void*)dst1, dst2, (void*)dst2);
    if (strcmp(dst1, dst2) == 0 && ret1 == ret2) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    ret1 = strlcpy(dst1, src, 5);
    ret2 = ft_strlcpy(dst2, src, 5);
    
    printf("Caso 2 Copia truncada: \n");
    printf("  Esperado: \"%.*s\" (Dir: %p), Obtenido: \"%.*s\" (Dir: %p)\n", 5, dst1, (void*)dst1, 5, dst2, (void*)dst2);
    if (strncmp(dst1, dst2, 5) == 0 && ret1 == ret2) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 2;
    }
    
    return test_fallido;
}
