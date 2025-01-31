#include "libft.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *a = "Hola que tal estas .";
	char *b = "Hola que tar";
	printf("%d", ft_strncmp(a,b,12));
	return 0;
}
