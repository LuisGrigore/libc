#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t len_s1 = ft_strlen(s1);
    size_t len_s2 = ft_strlen(s2);
    char *new_str = (char *)ft_calloc(len_s1 + len_s2 + 1,sizeof(char));

	if (!s1 || !s2)
	{
		return NULL;
	}

    if (!new_str)
        return NULL;

    size_t i = 0, j = 0;
    
    while (i < len_s1) {
        new_str[i] = s1[i];
        i++;
    }
    
    while (j < len_s2) {
        new_str[i + j] = s2[j];
        j++;
    }
    
    new_str[i + j] = '\0';
    return new_str;
}