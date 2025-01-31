#include "libft.h"
#include <stdio.h>

char *ft_strchr(const char *s, int c);

int main() {
    const char *str = "Hello, world!";
    
    // Probar con un carácter que está en la cadena
    char c1 = 'o';
    char *result1 = ft_strchr(str, c1);
    if (result1) {
        printf("Primer '%c' encontrado en la posición: %ld\n", c1, result1 - str);
    } else {
        printf("El carácter '%c' no se encontró.\n", c1);
    }

    // Probar con un carácter que no está en la cadena
    char c2 = 'z';
    char *result2 = ft_strchr(str, c2);
    if (result2) {
        printf("Primer '%c' encontrado en la posición: %ld\n", c2, result2 - str);
    } else {
        printf("El carácter '%c' no se encontró.\n", c2);
    }

    // Probar con el carácter nulo '\0', que debería devolver el final de la cadena
    char c3 = '\0';
    char *result3 = ft_strchr(str, c3);
    if (result3) {
        printf("Carácter nulo encontrado en la posición: %ld\n", result3 - str);
    } else {
        printf("El carácter nulo no se encontró.\n");
    }

    // Comparar con la versión estándar de strchr() para verificar que ambas son equivalentes
    char *standard_result1 = strchr(str, c1);
    char *standard_result2 = strchr(str, c2);
    char *standard_result3 = strchr(str, c3);

    // Verificar que los resultados coincidan
    if (result1 == standard_result1) {
        printf("La implementación personalizada de strchr() y la estándar coinciden para '%c'.\n", c1);
    } else {
        printf("La implementación personalizada de strchr() y la estándar NO coinciden para '%c'.\n", c1);
    }

    if (result2 == standard_result2) {
        printf("La implementación personalizada de strchr() y la estándar coinciden para '%c'.\n", c2);
    } else {
        printf("La implementación personalizada de strchr() y la estándar NO coinciden para '%c'.\n", c2);
    }

    if (result3 == standard_result3) {
        printf("La implementación personalizada de strchr() y la estándar coinciden para el carácter nulo.\n");
    } else {
        printf("La implementación personalizada de strchr() y la estándar NO coinciden para el carácter nulo.\n");
    }

    return 0;
}
