#include "libft.h"


void *ft_memset(void *v, int c, size_t s)
{
	char *str;
	str = v;
	while(s > 0)
	{
		str[s] = c;
		s--;
	}
	return v;
}