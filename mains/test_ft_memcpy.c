/* main_ft_memcpy.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_memcpy:\n");
    int test_fallido = 0;
    
    char src[] = "Prueba memcpy";
	printf("Contenido de la memoria a copiar: \"%s\"\n", src);
    char dest1[20] = {0}, dest2[20] = {0};
    
    memcpy(dest1, src, 7);
    ft_memcpy(dest2, src, 7);
    
    printf("Caso 1 Copia parcial: Esperado: %s, Obtenido: %s - ", dest1, dest2);
    if (memcmp(dest1, dest2, 7) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    memcpy(dest1, src, sizeof(src));
    ft_memcpy(dest2, src, sizeof(src));
    
    printf("Caso 2 Copia completa: Esperado: %s, Obtenido: %s - ", dest1, dest2);
    if (memcmp(dest1, dest2, sizeof(src)) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 2;
    }
    
    return test_fallido;
}