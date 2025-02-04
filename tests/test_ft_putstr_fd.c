/* main_ft_putstr_fd.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int main() {
    printf("Tests ft_putstr_fd:\n");
    int test_fallido = 0;
    
    // Crear y abrir un archivo temporal para escritura
    int fd = open("test_putstr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    // Cadenas de prueba, incluyendo casos límite
    const char *test_cases[] = {"Hola", "", "12345", "Prueba de escritura", "!@#$%^&*()", NULL};
    
    for (int i = 0; i < 6; i++) {
        if (test_cases[i] != NULL) {
            ft_putstr_fd((char *)test_cases[i], fd);
        } else {
            printf("Caso %d: Se intentó escribir NULL, ignorado.\n", i+1);
        }
    }
    close(fd);
    
    // Leer el contenido del archivo para verificar
    fd = open("test_putstr_fd.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al leer el archivo");
        return 1;
    }
    
    char obtenido[100] = {0};
    read(fd, obtenido, sizeof(obtenido) - 1);
    close(fd);
    
    // Unir las cadenas esperadas
    char esperado[100] = "";
    for (int i = 0; i < 6; i++) {
        if (test_cases[i] != NULL) {
            strcat(esperado, test_cases[i]);
        }
    }
    
    // Comparar el contenido escrito con lo esperado
    printf("Esperado: \"%s\"\n", esperado);
    printf("Obtenido: \"%s\"\n", obtenido);
    
    if (strcmp(esperado, obtenido) == 0) {
        printf("✔ PASA\n");
    } else {
        printf("✘ FALLA\n");
        test_fallido = 1;
    }
    
    // Eliminar archivo temporal
    remove("test_putstr_fd.txt");
    
    return test_fallido;
}