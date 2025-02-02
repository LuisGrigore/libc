#include <stdio.h>
#include "libft.h"


// Función para probar ft_strjoin y verificar el resultado
void test_ft_strjoin(char *s1, char *s2, char *expected) {
    char *result = ft_strjoin(s1, s2);
    
    printf("s1: \"%s\", s2: \"%s\"\n", s1 ? s1 : "(NULL)", s2 ? s2 : "(NULL)");
    printf("Resultado   : \"%s\"\n", result ? result : "(NULL)");
    printf("Esperado    : \"%s\"\n", expected ? expected : "(NULL)");
    
    free(result); // Liberar memoria si se asignó
    printf("-------------------------------------\n");
}

// Pruebas principales para ft_strjoin
void run_tests() {
    printf("🔹 Ejecutando pruebas para ft_strjoin()\n\n");

    // Caso 1: Cadenas normales
    test_ft_strjoin("Hola, ", "mundo!", "Hola, mundo!");

    // Caso 2: Primera cadena vacía
    test_ft_strjoin("", "Test", "Test");

    // Caso 3: Segunda cadena vacía
    test_ft_strjoin("Prueba", "", "Prueba");

    // Caso 4: Ambas cadenas vacías
    test_ft_strjoin("", "", "");

    // Caso 5: Cadenas con espacios
    test_ft_strjoin("Hola ", " mundo", "Hola  mundo");

    // Caso 6: Cadenas con caracteres especiales
    test_ft_strjoin("123", "!@#", "123!@#");

    // Caso 7: Primera cadena NULL (debe retornar NULL)
    test_ft_strjoin(NULL, "Texto", NULL);

    // Caso 8: Segunda cadena NULL (debe retornar NULL)
    test_ft_strjoin("Texto", NULL, NULL);

    // Caso 9: Ambas cadenas NULL (debe retornar NULL)
    test_ft_strjoin(NULL, NULL, NULL);

    // Caso 10: Cadenas largas (para verificar malloc)
    char *long_str1 = "Esta es una cadena larga ";
    char *long_str2 = "para probar malloc correctamente.";
    test_ft_strjoin(long_str1, long_str2, "Esta es una cadena larga para probar malloc correctamente.");
}

int main() {
    run_tests();
    return 0;
}
