#include "libft.h"

char *ft_strdup(const char *s)
{
	char *new_str;
	int i;

	i = 0;
	new_str = (char *) malloc((ft_strlen(s)+1) * sizeof(char));
	if(!s || !new_str)
	{
		return NULL;
	}
	while(s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}
