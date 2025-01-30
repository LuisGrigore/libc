#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    int i;
    char *s;
    char *d;

	s = (char *) src;
	d = (char *) dest;

    if (src < dest) {
		i = n - 1;
        while (i >= 0) {
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