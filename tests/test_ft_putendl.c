#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static int  get_length(int n)
{
    int len = (n <= 0) ? 1 : 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

char    *ft_itoa(int n)
{
    int     len = get_length(n);
    char    *str;
    long    num = n;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    while (len-- > 0)
    {
        if (str[len] == '-')
            break;
        str[len] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}

void ft_putendl_fd(char *s, int fd) {
    if (s && fd >= 0) {
        write(fd, s, strlen(s));
        write(fd, "\n", 1);
    }
}

int main() {
    printf("Tests ft_putendl_fd:\n");
    int test_fallido = 0;
    
    const char *test_cases[] = {"Hola Mundo", "1234567890", "abcdef", "", "aaaaa"};
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("Error al abrir archivo\n");
        return 1;
    }
    
    for (int i = 0; i < 5; i++) {
        ft_putendl_fd((char *)test_cases[i], fd);
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
    
    printf("Contenido del archivo:\n%s\n", buffer);
    return test_fallido;
}
