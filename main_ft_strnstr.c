#include <stdio.h>
#include <string.h>
#include "libft.h"

// Declaración de la función strnstr (nuestra implementación)

// Función principal para las pruebas
int main() {
    const char *big = "Este es un ejemplo de búsqueda en C";
    const char *little = "ejemplo";
    size_t len;

    // Caso 1: little es una cadena vacía
    len = 30;
    printf("Caso 1: little es una cadena vacía\n");
    printf("Resultado esperado: %s\n", big);
    printf("Resultado obtenido: %s\n", ft_strnstr(big, "", len));  // Esperado: big

    // Caso 2: little se encuentra en big dentro del límite de len
    len = 30;
    printf("\nCaso 2: little se encuentra en big dentro del límite de len\n");
    printf("Resultado esperado: ejemplo de búsqueda en C\n");
    printf("Resultado obtenido: %s\n", ft_strnstr(big, little, len));  // Esperado: "ejemplo de búsqueda en C"

    // Caso 3: little no se encuentra en big dentro del límite de len
    len = 10;
    printf("\nCaso 3: little no se encuentra en big dentro del límite de len\n");
    printf("Resultado esperado: NULL\n");
    printf("Resultado obtenido: %s\n", ft_strnstr(big, little, len) ? ft_strnstr(big, little, len) : "NULL");  // Esperado: NULL

    // Caso 4: Se excede el límite de len (pero little se encuentra)
    len = 40;
    printf("\nCaso 4: Se excede el límite de len (pero little se encuentra)\n");
    printf("Resultado esperado: ejemplo de búsqueda en C\n");
    printf("Resultado obtenido: %s\n", ft_strnstr(big, little, len));  // Esperado: "ejemplo de búsqueda en C"


    // Caso 6: Subcadena está justo al final de los len caracteres
    len = 35;  // big tiene 35 caracteres, el límite de len es justo el tamaño de big
    printf("\nCaso 6: Subcadena está justo al final de los len caracteres\n");
    printf("Resultado esperado: en C\n");
    printf("Resultado obtenido: %s\n", ft_strnstr(big, "en C", len));  // Esperado: "en C"

    // Caso 7: little no se encuentra en big, con len suficiente
    len = 10;
    printf("\nCaso 7: little no se encuentra en big, con len suficiente\n");
    printf("Resultado esperado: NULL\n");
    printf("Resultado obtenido: %s\n", ft_strnstr(big, "noexiste", len) ? ft_strnstr(big, "noexiste", len) : "NULL");  // Esperado: NULL

    // Caso 8: Subcadena se encuentra justo al principio
    len = 10;
    printf("\nCaso 8: Subcadena se encuentra justo al principio\n");
    printf("Resultado esperado: Este es un ejemplo de búsqueda en C\n");
    printf("Resultado obtenido: %s\n", ft_strnstr(big, "Este", len));  // Esperado: "Este es un ejemplo de búsqueda en C"

    return 0;
}