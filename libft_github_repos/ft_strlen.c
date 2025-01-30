#include "libft.h"

size_t ft_strlen(const char* s)
{
	int num;
	
	num = 0;
    if (s == NULL) {
        return 0;
    }
    while (s[num] != '\0') {
        num++;
    }
    return num;
}
