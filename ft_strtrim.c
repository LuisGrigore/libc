#include "libft.h"

static int ft_is_in_set(char c, const char *set) {
    while (*set) {
        if (*set == c)
            return 1;
        set++;
    }
    return 0;
}
char	*ft_strtrim(char const *s1, char const *set)
{
    if (!s1 || !set)
        return NULL;

    size_t start = 0;
    size_t end = ft_strlen(s1);
    while (s1[start] && ft_is_in_set(s1[start], set))
        start++;
    while (end > start && ft_is_in_set(s1[end - 1], set))
        end--;
    size_t new_len = end - start;
    char *trimmed_str = (char *)ft_calloc(new_len + 1, sizeof(char));
    if (!trimmed_str)
        return NULL;
    for (size_t i = 0; i < new_len; i++)
        trimmed_str[i] = s1[start + i];

    return trimmed_str;
}