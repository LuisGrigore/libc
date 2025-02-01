#include "libft.h"
void *ft_calloc(size_t nmemb, size_t size)
{
	if(nmemb * size == 0)
	{

	}
	int *ptr = (int *) malloc(nmemb * size);
	int i = 0;
	while(i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (void *) ptr;
}