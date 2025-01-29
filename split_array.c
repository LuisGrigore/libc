#include "split_array.h"

void *memmove(void *dest, const void *src, size_t n)
{
    int i;
    char *s = (char *) src;
    char *d = (char *) dest;

    if (src < dest) {
        for (i = n - 1; i >= 0; i--) {
            d[i] = s[i];
        }
    } else {
        for (i = 0; i < n; i++) {
            d[i] = s[i];
        }
    }
    return dest;
}

void free_array(char **array, int size)
{
    for (int i = 0; i < size; i++) {
        free(array[i]);  // No olvides incrementar i
    }
    free(array);
}

void *ft_realloc(void *ptr, size_t new_size)
{
    void *new_ptr = malloc(new_size);
    if (!new_ptr) {
        return NULL;  // Comprobación de error de malloc
    }
    new_ptr = memmove(new_ptr, ptr, new_size);
    free(ptr);  // Libera la memoria original después de mover los datos
    return new_ptr;
}

struct SplitArray *add_to_split_array(struct SplitArray *split_array, char *str)
{
    if (split_array->array == NULL) {
        split_array->array = (char **) malloc(sizeof(char *));
        split_array->array[0] = str;
    } else {
        split_array->array = (char **) ft_realloc(split_array->array, (split_array->size + 1) * sizeof(char *));
        split_array->array[split_array->size] = str;  // Coloca el nuevo string en la posición correcta
    }
    split_array->size++;
    return split_array;  // Es importante retornar el puntero actualizado
}

void add_null_to_split_array(struct SplitArray *split_array)
{
    // Asignar memoria para un nuevo espacio en el arreglo para el puntero NULL
    split_array->array = (char **) ft_realloc(split_array->array, (split_array->size + 1) * sizeof(char *));
    
    // Establecer el último puntero como NULL
    split_array->array[split_array->size] = NULL;
	split_array->last = split_array->array[split_array->size];
	split_array->size++;

}

struct SplitArray SplitArray()
{
    struct SplitArray sa;
    sa.array = NULL;
    sa.size = 0;
    return sa;  // No es necesario inicializar last aquí, ya que no se utiliza al principio
}
