#include "libft.h"
#include <stdio.h>

char *substr(char *str, int start, int end);
char **add_to_split_array(char ** src, char* str, int size);

char **ft_split(char const *s, char c)
{
	int i = 0;
	int j = 0;
	int res_size = 1;
	char *str = s;
	char ** result = (char **) malloc(sizeof(char*));

	while(str[j] != '\0')
	{
		if(str[j] == c || str[j+1] == '\0')
		{
			if(i != j)
			{
				if(str[j+1] == '\0')
				{
					printf("%s\n",substr(str,i,j+1));
					printf("%d\n",res_size);
					result = add_to_split_array(result,substr(str,i,j+1),res_size);
					printf("%d",result);

				}
				else
				{
					printf("%s\n",substr(str,i,j));
					printf("%d\n",res_size);
					result = add_to_split_array(result,substr(str,i,j),res_size);
					printf("%d",result);
				}
				res_size++;
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



char *substr(char *str, int start, int end)
{
	int size = end-start;
	char *result = (char*) malloc(size + 1 * sizeof(char));
	int i = 0;
	while(i < size)
	{
		result[i] = str[start + i];
		i ++;
	}
	result[size] = '\0';
	return result;
}

void *memmove(void *dest, const void *src, size_t n)
{
	int i;
	char *s;
	char *d;

	i = 0;
	s = (char *) src;
	d = (char *) dest;

	if(src < dest)
	{
		while(i < n)
		{
			d[(n-1)-i] = s[(n-1)-i];
			i++;
		}
	}
	else
	{
		while(i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return dest;
}
char **add_to_split_array(char ** src, char* str, int size)
{
	char **result;
	result = (char **) malloc((size + 1) * sizeof(char *));
	memmove(result,src, size);
	result[size] = str;
	free(src);
	return result;
}