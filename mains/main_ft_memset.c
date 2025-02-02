/* main_ft_memset.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_memset:\n");
    int test_fallido = 0;
    
    char buffer1[20], buffer2[20];
    memset(buffer1, 'A', sizeof(buffer1));
    ft_memset(buffer2, 'A', sizeof(buffer2));
    
    printf("Caso 1 Llenado completo: ");
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    memset(buffer1, 'B', 10);
    ft_memset(buffer2, 'B', 10);
    
    printf("Caso 2 Llenado parcial: ");
    if (memcmp(buffer1, buffer2, 10) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 2;
    }
    
    return test_fallido;
}