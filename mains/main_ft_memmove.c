/* main_ft_memmove.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_memmove:\n");
    int test_fallido = 0;
    
    char src[] = "Prueba memmove";
    char dest1[20] = {0}, dest2[20] = {0};
    
    memmove(dest1, src, 7);
    ft_memmove(dest2, src, 7);
    
    printf("Caso 1 Copia parcial: ");
    if (memcmp(dest1, dest2, 7) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    memmove(dest1, src, sizeof(src));
    ft_memmove(dest2, src, sizeof(src));
    
    printf("Caso 2 Copia completa: ");
    if (memcmp(dest1, dest2, sizeof(src)) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 2;
    }
    
    // Caso especial: solapamiento
    char buffer1[] = "SolapamientoMemmove";
    char buffer2[] = "SolapamientoMemmove";
    
    memmove(buffer1 + 5, buffer1, 10);
    ft_memmove(buffer2 + 5, buffer2, 10);
    
    printf("Caso 3 Solapamiento: ");
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 3;
    }
    
    return test_fallido;
}
