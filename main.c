#include "ft_split_copy.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *a = "   Hola  que    tal asfafa dfsdg sg    ";
	char ** b = ft_split(a, ' ');
	int i = 0;
	while (i< 6)
	{
		printf("c: %s\n", b[i]);
		i++;
	}
	

	return 0;
}
