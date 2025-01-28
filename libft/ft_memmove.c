#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	int i;
	char *s;
	char *d;

	i = 0;
	s = (char *) src;
	d = (char *) dest;

	if(src < dest)
	{
		while(i < n)
		{
			d[(n-1)-i] = s[(n-1)-i];
			i++;
		}
	}
	else
	{
		while(i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return dest;
}