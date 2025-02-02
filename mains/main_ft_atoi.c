#include <stdio.h>
#include "libft.h"
#include <limits.h>

// Función para probar y comparar ft_atoi con atoi
void test_ft_atoi() {
    char *tests[] = {
        "42",                     // Número positivo
        "   -123",                // Número negativo con espacios iniciales
        "+567",                   // Número con signo positivo
        "42abc",                  // Número seguido de caracteres inválidos
        "  00123",                // Número con ceros iniciales
        "-2147483648",            // INT_MIN
        "2147483647",             // INT_MAX
        "9223372036854775807",    // Desbordamiento (debería dar INT_MAX)
        "-9223372036854775808",   // Desbordamiento (debería dar INT_MIN)
        "abc",                    // Cadena sin números (debería devolver 0)
        "  -+123",                // Signo inválido (debería devolver 0)
        "  123 456",              // Número con espacios en medio (debería tomar solo el primer número)
        NULL                      // Fin de los casos de prueba
    };

    printf("Comparación entre ft_atoi y atoi:\n\n");

    for (int i = 0; tests[i] != NULL; i++) {
        printf("Test \"%s\":\n", tests[i]);
        printf("  ft_atoi: %d\n", ft_atoi(tests[i]));
        printf("  atoi   : %d\n", atoi(tests[i]));
        printf("-------------------------\n");
    }
}

int main() {
    test_ft_atoi();
	
    return 0;
}
