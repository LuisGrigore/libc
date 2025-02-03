/* main_ft_strlcpy.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t manual_strlcpy(char *dst, const char *src, size_t size) {
    size_t i;
    for (i = 0; i + 1 < size && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    if (size > 0) {
        dst[i] = '\0';
    }
    while (src[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    printf("Tests ft_strlcpy:\n");
    int test_fallido = 0;
    
    char src[] = "Prueba strlcpy";
    printf("Texto de prueba: \"%s\".\n", src);
    char dst1[20], dst2[20];
    size_t ret1, ret2;
    
    ret1 = manual_strlcpy(dst1, src, sizeof(dst1));
    ret2 = ft_strlcpy(dst2, src, sizeof(dst2));
    
    printf("Caso 1 Copia completa: \n");
    printf("  Esperado: \"%s\", Obtenido: \"%s\"\n", dst1, dst2);
    if (strcmp(dst1, dst2) == 0 && ret1 == ret2) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    ret1 = manual_strlcpy(dst1, src, 5);
    ret2 = ft_strlcpy(dst2, src, 5);
    
    printf("Caso 2 Copia truncada: \n");
    printf("  Esperado: \"%.*s\", Obtenido: \"%.*s\"\n", 5, dst1, 5, dst2);
    if (strncmp(dst1, dst2, 5) == 0 && ret1 == ret2) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 2;
    }
    
    return test_fallido;
}