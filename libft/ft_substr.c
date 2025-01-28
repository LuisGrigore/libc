#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substring;
	int end;
	end = len-1;
	substring = (char*) malloc(len + 1 * sizeof(char));
	if(!substring)
	{
		return NULL;
	}
	ft_strncpy(substring, s + start, len);
    substring[len] = '\0';
	return (substring);
}