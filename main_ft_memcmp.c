int main() {
    // Definimos dos áreas de memoria para comparar
    char buffer1[] = "Hello, world!";
    char buffer2[] = "Hello, world!";
    char buffer3[] = "Hello, C!";

    // Comparar buffer1 y buffer2 (deberían ser iguales)
    int result1 = ft_memcmp(buffer1, buffer2, sizeof(buffer1));
    if (result1 == 0) {
        printf("buffer1 y buffer2 son iguales.\n");
    } else {
        printf("buffer1 y buffer2 son diferentes.\n");
    }

    // Comparar buffer1 y buffer3 (deberían ser diferentes)
    int result2 = ft_memcmp(buffer1, buffer3, sizeof(buffer1));
    if (result2 == 0) {
        printf("buffer1 y buffer3 son iguales.\n");
    } else {
        printf("buffer1 y buffer3 son diferentes.\n");
    }

    // Comparar los primeros 5 bytes de buffer1 y buffer3
    int result3 = ft_memcmp(buffer1, buffer3, 5);
    if (result3 == 0) {
        printf("Los primeros 5 bytes de buffer1 y buffer3 son iguales.\n");
    } else {
        printf("Los primeros 5 bytes de buffer1 y buffer3 son diferentes.\n");
    }

    return 0;
}