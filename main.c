#include "ft_split.c"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char *a = "Hola  que    tal ";
	char ** b = ft_split(a, ' ');
	//char * c = substr(a,1,4);
	//printf("c: %s", b[0]);
	write(1,b[2],4);
	return 0;
}
