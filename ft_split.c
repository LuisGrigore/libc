#include "libft.h"
#include <stdio.h>

char *substr(char *str, int start, int end);
int count_instances(char* str, char c);
int is_begin(char* str, char c);
int is_end(char* str, char c);

char **ft_split(char const *s, char c)
{
	int i = 0;
	int j = 0;
	char str = s;
	while(str[j] != '\0')
	{
		if(str[j] == c)
		{
			if(i != j)
			{
				//añadir string al arry
				printf(substr(str,i,j-1));
			}
			i = j;
			i++;
			j++;
		}
		else
		{
			j++;
		}

	}
	
}




















int is_begin(char* str, char c)
{
	if(str[0] == c)
	{
		return 1;
	}
	return 0;
}

int is_end(char* str, char c)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	if(str[i-1] == c)
	{
		return 1;
	}
	return 0;
}

int count_instances(char* str, char c)
{
	int i = 0;
	int result = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
		{
			result ++;
		}
		i++;
	}
	return result;
}

char *substr(char *str, int start, int end)
{
	int size = end-start;
	char *result = (char*) malloc(size * sizeof(char));
	int i = 0;
	while(i < size)
	{
		result[i] = str[start + i];
		i ++;
	}
	return result;
}