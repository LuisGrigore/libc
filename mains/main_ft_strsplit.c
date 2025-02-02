/* main_ft_split.c */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void print_split_result(char **result) {
    if (!result) {
        printf("NULL\n");
        return;
    }
    for (int i = 0; result[i]; i++) {
        printf("\"%s\" ", result[i]);
    }
    printf("\n");
}

int main() {
    printf("Tests ft_split:\n");
    int test_fallido = 0;
    
    struct {
        const char *s;
        char c;
        const char *esperado[5];
    } test_cases[] = {
        {"Hola Mundo", ' ', {"Hola", "Mundo", NULL}},
        {"123,456,789", ',', {"123", "456", "789", NULL}},
        {"abc--def--ghi", '-', {"abc", "def", "ghi", NULL}},
        {"sin_delimitador", 'x', {"sin_delimitador", NULL}},
        {"", ' ', {NULL}}
    };
    
    for (int i = 0; i < 5; i++) {
        char **obtenido = ft_split(test_cases[i].s, test_cases[i].c);
        printf("Caso %d Separando \"%s\" por '%c': ", i+1, test_cases[i].s, test_cases[i].c);
        
        int j;
        for (j = 0; test_cases[i].esperado[j] && obtenido[j]; j++) {
            if (strcmp(test_cases[i].esperado[j], obtenido[j]) != 0) {
                printf("✘ FALLA\n");
                test_fallido = i+1;
                break;
            }
        }
        
        if (!test_cases[i].esperado[j] && !obtenido[j]) {
            printf("✔ PASA\n");
        } else if (test_fallido == 0) {
            printf("✘ FALLA\n");
            test_fallido = i+1;
        }
        
        // Liberar memoria
        for (int k = 0; obtenido && obtenido[k]; k++) {
            free(obtenido[k]);
        }
        free(obtenido);
    }
    
    return test_fallido;
}
