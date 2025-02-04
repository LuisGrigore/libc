#include "libft.h"

static int  get_length(int n)
{
    int len = (n <= 0) ? 1 : 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

char    *ft_itoa(int n)
{
    int     len = get_length(n);
    char    *str;
    long    num = n;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    while (len-- > 0)
    {
        if (str[len] == '-')
            break;
        str[len] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}