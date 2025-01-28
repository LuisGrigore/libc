#include "libft.h"

int ft_strlen(char* s)
{
	int num;
	num = 0;
	while(s[num] != '\0')
	{
		num++;
	}
	return num;
}
