#include <stdio.h>
#include "libft.h"

// Función para imprimir un array de enteros
void print_int_array(const char *label, int *arr, size_t size) {
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Función de prueba comparando ft_calloc con calloc
void test_ft_calloc() {
    printf("🔹 Prueba 1: Asignación de un array de enteros\n");
    int *ft_arr = (int *)ft_calloc(5, sizeof(int));
    int *std_arr = (int *)calloc(5, sizeof(int));

    if (ft_arr && std_arr) {
        print_int_array("ft_calloc", ft_arr, 5);  // Esperado: 0 0 0 0 0
        print_int_array("calloc   ", std_arr, 5); // Esperado: 0 0 0 0 0
    }
    free(ft_arr);
    free(std_arr);

    printf("\n🔹 Prueba 2: Asignación de una cadena de caracteres\n");
    char *ft_str = (char *)ft_calloc(10, sizeof(char));
    char *std_str = (char *)calloc(10, sizeof(char));

    if (ft_str && std_str) {
        printf("ft_calloc: \"%s\"\n", ft_str); // Esperado: ""
        printf("calloc   : \"%s\"\n", std_str); // Esperado: ""
    }
    free(ft_str);
    free(std_str);

    printf("\n🔹 Prueba 3: Asignación de estructura\n");
    typedef struct {
        int id;
        double saldo;
    } Cliente;

    Cliente *ft_cliente = (Cliente *)ft_calloc(1, sizeof(Cliente));
    Cliente *std_cliente = (Cliente *)calloc(1, sizeof(Cliente));

    if (ft_cliente && std_cliente) {
        printf("ft_calloc: Cliente ID=%d, Saldo=%.2f\n", ft_cliente->id, ft_cliente->saldo); // Esperado: ID=0, Saldo=0.00
        printf("calloc   : Cliente ID=%d, Saldo=%.2f\n", std_cliente->id, std_cliente->saldo); // Esperado: ID=0, Saldo=0.00
    }
    free(ft_cliente);
    free(std_cliente);

    printf("\n🔹 Prueba 4: Asignación de tamaño 0\n");
    void *ft_zero_alloc = ft_calloc(0, sizeof(int));
    void *std_zero_alloc = calloc(0, sizeof(int));

    printf("ft_calloc: %s\n", ft_zero_alloc ? "Puntero válido" : "NULL");
    printf("calloc   : %s\n", std_zero_alloc ? "Puntero válido" : "NULL");
    free(ft_zero_alloc);
    free(std_zero_alloc);

    printf("\n🔹 Prueba 5: Desbordamiento intencional (seguridad)\n");
    size_t big_size = (size_t)-1 / 2; // Intento de desbordamiento
    void *ft_overflow_test = ft_calloc(big_size, big_size);
    void *std_overflow_test = calloc(big_size, big_size);

    printf("ft_calloc: %s\n", ft_overflow_test ? "Puntero válido (¡cuidado!)" : "NULL esperado");
    printf("calloc   : %s\n", std_overflow_test ? "Puntero válido (¡cuidado!)" : "NULL esperado");
    free(ft_overflow_test);
    free(std_overflow_test);
}

int main() {
    test_ft_calloc();
    return 0;
}
