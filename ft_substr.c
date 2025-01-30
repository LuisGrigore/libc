#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    if (!s) {
        return NULL;
    }

    size_t str_len = ft_strlen(s);

    if (start >= str_len) {
        return (char *)calloc(1, sizeof(char));
    }

    if (start + len > str_len) {
        len = str_len - start;
    }

    char *substring = (char *)malloc((len + 1) * sizeof(char));
    if (!substring) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        substring[i] = s[start + i];
    }

    substring[len] = '\0';
    return substring;
}
