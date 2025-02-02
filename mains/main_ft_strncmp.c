#include "libft.h"
#include <stdio.h>

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, world!";
    const char *str3 = "Hello, C!";
    const char *str4 = "Hello, World!";
    
    // Comparar los primeros 5 caracteres de str1 y str2
    int result1 = ft_strncmp(str1, str2, 5);
    if (result1 == 0) {
        printf("Los primeros 5 caracteres de str1 y str2 son iguales.\n");
    } else if (result1 < 0) {
        printf("Los primeros 5 caracteres de str1 son menores que los de str2.\n");
    } else {
        printf("Los primeros 5 caracteres de str1 son mayores que los de str2.\n");
    }

    // Comparar los primeros 10 caracteres de str1 y str3
    int result2 = ft_strncmp(str1, str3, 10);
    if (result2 == 0) {
        printf("Los primeros 10 caracteres de str1 y str3 son iguales.\n");
    } else if (result2 < 0) {
        printf("Los primeros 10 caracteres de str1 son menores que los de str3.\n");
    } else {
        printf("Los primeros 10 caracteres de str1 son mayores que los de str3.\n");
    }

    // Comparar los primeros 5 caracteres de str1 y str4 (deberían ser iguales)
    int result3 = ft_strncmp(str1, str4, 5);
    if (result3 == 0) {
        printf("Los primeros 5 caracteres de str1 y str4 son iguales.\n");
    } else if (result3 < 0) {
        printf("Los primeros 5 caracteres de str1 son menores que los de str4.\n");
    } else {
        printf("Los primeros 5 caracteres de str1 son mayores que los de str4.\n");
    }

    return 0;
}
