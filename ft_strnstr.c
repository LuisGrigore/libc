#include  "libft.h"
#include <string.h>
#include <stdio.h>

//TO DO: arreglar esto
char *ft_strnstr(const char *big, const char *little, size_t len) {
    size_t i, j;

    if (*little == '\0')
        return ((char *)big);

    for (j = 0; big[j] && j < len; j++) {
        i = 0;

        while ((j + i) < len && big[j + i] && little[i] && big[j + i] == little[i])
        {

			i++;
			if (i + j == len)
			{

			}
		}
        if (little[i] == '\0')
		{
            return ((char *)&big[j]);
		}
    }
    return NULL;
}
