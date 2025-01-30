#include "split_array.h"
#include "libft.h"



void free_array(char **array, int size)
{
	int i;

	i = 0;
    while (i < size) {
        free(array[i]);
		i++;
    }
    free(array);
}

void *ft_realloc(void *ptr, size_t new_size)
{
    void *new_ptr = malloc(new_size);
    if (!new_ptr) {
        return NULL;
    }
    new_ptr = ft_memmove(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}

struct SplitArray *add_to_split_array(struct SplitArray *split_array, char *str)
{
    if (split_array->array == NULL) {
        split_array->array = (char **) malloc(sizeof(char *));
        split_array->array[0] = str;
    } else {
        split_array->array = (char **) ft_realloc(split_array->array, (split_array->size + 1) * sizeof(char *));
        split_array->array[split_array->size] = str;
    }
    split_array->size++;
    return split_array;
}

void add_null_to_split_array(struct SplitArray *split_array)
{
    split_array->array = (char **) ft_realloc(split_array->array, (split_array->size + 1) * sizeof(char *));
    
    split_array->array[split_array->size] = NULL;
	split_array->last = split_array->array[split_array->size];
	split_array->size++;

}

struct SplitArray SplitArray()
{
    struct SplitArray sa;
    sa.array = NULL;
    sa.size = 0;
    return sa;
}
