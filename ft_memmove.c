#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	//TO DO:: hacer que int sea size_t
    int i;
    char *s;
    char *d;

    s = (char *) src;
    d = (char *) dest;

    if ((s < d) && (n > 0)) {
		i = n - 1;
        while (i >= 0) 
		{
            d[i] = s[i];
			i--; 
        }
    } else {
        i = 0;
        while (i < n) {
            d[i] = s[i];
            i++;
        }
    }
    return dest;
}