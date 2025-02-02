#include "libft.h"

char *ft_strdup(const char *s)
{
    char *new_str;
    int i;

    if (!s)
        return NULL;

    new_str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
    if (!new_str)
        return NULL;

    i = 0;
    while (s[i])
    {
        new_str[i] = s[i];
        i++;
    }

    return new_str;
}
