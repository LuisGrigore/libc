/* main_ft_memset.c */
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_memset:\n");
    int test_fallido = 0;
	int n = 20;
    
    char *buffer1 = (char *)malloc(n * sizeof(char));
	char *buffer2 = (char *)malloc(n * sizeof(char));
    memset(buffer1, 'A', n);
    ft_memset(buffer2, 'A', n);
    
    printf("Caso 1 Llenado completo: Esperado: %s, Obtenido: %s - ", buffer1, buffer2);
    if (memcmp(buffer1, buffer2, n) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    memset(buffer1, 'B', 10);
    ft_memset(buffer2, 'B', 10);
    
    printf("Caso 2 Llenado parcial: Esperado: %.*s, Obtenido: %.*s - ", 10, buffer1, 10, buffer2);
    if (memcmp(buffer1, buffer2, 10) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        if (test_fallido == 0) test_fallido = 2;
    }

	free(buffer1);
	free(buffer2);
    
    return test_fallido;
}