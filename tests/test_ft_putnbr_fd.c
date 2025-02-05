#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd);

int main() {
    printf("Tests ft_putnbr_fd:\n");
    int test_fallido = 0;
    
    struct {
        int n;
        const char *expected;
    } test_cases[] = {
        {1234, "1234"},
        {-5678, "-5678"},
        {0, "0"},
        {42, "42"},
        {-1, "-1"},
        {987654321, "987654321"},
        {-2147483648, "-2147483648"},
        {2147483647, "2147483647"}
    };
    
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("Error al abrir archivo\n");
        return 1;
    }
    
    for (int i = 0; i < 8; i++) {
        ft_putnbr_fd(test_cases[i].n, fd);
        write(fd, "\n", 1);
    }
    close(fd);
    
    fd = open("test_output.txt", O_RDONLY);
    if (fd < 0) {
        printf("Error al leer archivo\n");
        return 1;
    }
    
    char buffer[256];
    int read_bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (read_bytes < 0) {
        printf("Error al leer contenido\n");
        return 1;
    }
    buffer[read_bytes] = '\0';
    close(fd);
    
    char *line = strtok(buffer, "\n");
    for (int i = 0; i < 8; i++) {
        printf("Caso %d %d: Esperado: \"%s\", Obtenido: \"%s\" - ", i+1, test_cases[i].n, test_cases[i].expected, line);
        if (strcmp(line, test_cases[i].expected) == 0) {
            printf("✔ PASA\n");
        } else {
            printf("✘ FALLA\n");
            if (test_fallido == 0) test_fallido = i+1;
        }
        line = strtok(NULL, "\n");
    }
    
    return test_fallido;
}
