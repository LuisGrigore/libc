#include "libft.h"
#include <stdio.h>

char *substr(char *str, int start, int end);
int count_instances(char* str, char c);
int is_begin(char* str, char c);
int is_end(char* str, char c);

char **ft_split(char const *s, char c)
{
	char ** result;
	int result_len;

	result_len = 0;

	char * str = s;
	char * temp;
	int res_i = 0;
	int i = 0;
	int j = 0;
	int len = 0;

	result_len = count_instances(str, c) + 1;

	if(is_begin(str,c) == 1)
	{
		result_len --;
	}
	if(is_end(str,c) == 1)
	{
		result_len --;
	}

	printf("%d", result_len);

	result = (char **) malloc(result_len * sizeof(char*));

	while(str[i] != '\0')
	{
		if(str[i] == c)
		{
			result[res_i] = substr(str,j,i);
			res_i ++;
			j = i+1;
		}
		i++;

	}
	if(res_i < result_len)
	{
		result[res_i] = substr(str,j,i);
	}
	return result;
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