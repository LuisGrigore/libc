/* main_ft_putchar_fd.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_putchar_fd:\n");
    int test_fallido = 0;
    
    // Crear y abrir un archivo temporal para escritura
    int fd = open("test_putchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    // Caracteres de prueba
    char test_cases[] = {'A', 'z', '0', '\n', '!'};
    char esperado[] = {'A', 'z', '0', '\n', '!', '\0'};  // Corregido con terminador nulo
    
    for (int i = 0; i < 5; i++) {
        ft_putchar_fd(test_cases[i], fd);
    }
    close(fd);
    
    // Leer el contenido del archivo para verificar
    fd = open("test_putchar_fd.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al leer el archivo");
        return 1;
    }
    
    char obtenido[6] = {0};  // Corregido: aseguramos terminador nulo
    read(fd, obtenido, sizeof(esperado) - 1);
    close(fd);
    
    // Comparar el contenido escrito con lo esperado
    printf("Esperado: \"%s\"\n", esperado);
    printf("Obtenido: \"%s\"\n", obtenido);
    
    if (strncmp(esperado, obtenido, 5) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    // Eliminar archivo temporal
    remove("test_putchar_fd.txt");
    
    return test_fallido;
}