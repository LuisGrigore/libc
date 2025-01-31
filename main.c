#include "ft_split_copy.h"
#include <stdio.h>

int main()
{
    char *a = "   Hola  que    tal asfafa dfsdg sg    ";
    char **b = ft_split(a, ' ');
    int i = 0;

    while (i < 6)
    {
        printf("c: %s\n", b[i]);
        i++;
    }

	i = 0;
	while(b[i] != NULL)
	{
		free(b[i]);
		i++;

	}
	free(b);

    return 0;
}
