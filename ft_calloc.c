#include "libft.h"
void *ft_calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;

    if (nmemb != 0 && total_size / nmemb != size)
        return NULL;

    void *ptr = malloc(total_size);
    if (!ptr)
        return NULL;

    unsigned char *byte_ptr = (unsigned char *)ptr;
    for (size_t i = 0; i < total_size; i++)
        byte_ptr[i] = 0;

    return ptr;
}