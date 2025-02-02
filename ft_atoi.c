#include "libft.h"
int	ft_atoi(const char *nptr)
{
    int i = 0;
    int signo = 1;
    long resultado = 0;

    while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
           nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
        i++;

    if (nptr[i] == '-' || nptr[i] == '+') {
        if (nptr[i] == '-')
            signo = -1;
        i++;
    }

    while (nptr[i] >= '0' && nptr[i] <= '9') {
        resultado = (resultado * 10) + (nptr[i] - '0');
        i++;
    }

    return (int)(resultado * signo);
}
