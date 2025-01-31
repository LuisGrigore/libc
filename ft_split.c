#include "libft.h"
#include "ft_split_copy.h"


struct SplitArray		*add_to_split_array(struct SplitArray *split_array,
							char *str);
void					add_null_to_split_array(struct SplitArray *split_array);
struct SplitArray		split_array_init(void);
struct StringExtractor	string_extractor_init(const char *str);
int						is_end(struct StringExtractor se);
char					*extract(struct StringExtractor *se, char regx);

// String extractor
struct StringExtractor	string_extractor_init(const char *str)
{
	struct StringExtractor	string_extractor;

	string_extractor.str = str;
	string_extractor.i = 0;
	string_extractor.j = 0;
	return (string_extractor);
}

char	*start_end_substr(const char *str, unsigned int start, unsigned int end)
{
	size_t	len;

	len = (size_t)(end - start);
	if (str == NULL || start >= end)
	{
		return (NULL);
	}
	return (ft_substr(str, start, len));
}

char	*extract(struct StringExtractor *se, char regx)
{
	char	*res;

	while (se->str[se->j] == regx && se->str[se->j] != '\0')
	{
		se->j++;
		se->i = se->j;
	}
	while (se->str[se->j] != regx && se->str[se->j] != '\0')
	{
		se->j++;
	}
	if (se->str[se->j] == '\0')
	{
		res = start_end_substr(se->str, se->i, se->j);
	}
	else
	{
		res = start_end_substr(se->str, se->i, se->j);
	}
	return (res);
}

int	is_end(struct StringExtractor se)
{
	if (se.str[se.j] == '\0')
	{
		return (1);
	}
	return (0);
}

// Split_Array

void	free_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		return (NULL);
	}
	ft_memmove(new_ptr, ptr, new_size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

struct SplitArray	*add_to_split_array(struct SplitArray *split_array,
		char *str)
{
	if (split_array->array == NULL)
	{
		split_array->array = (char **)malloc(sizeof(char *));
		split_array->array[0] = str;
	}
	else
	{
		split_array->array = (char **)ft_realloc(split_array->array,
				(split_array->size + 1) * sizeof(char *));
		split_array->array[split_array->size] = str;
	}
	split_array->size++;
	return (split_array);
}

void	add_null_to_split_array(struct SplitArray *split_array)
{
	split_array->array = (char **)ft_realloc(split_array->array,
			(split_array->size + 1) * sizeof(char *));
	split_array->array[split_array->size] = NULL;
	split_array->last = &split_array->array[split_array->size];
	split_array->size++;
}

struct SplitArray	split_array_init(void)
{
	struct SplitArray	split_array;

	split_array.array = NULL;
	split_array.size = 0;
	return (split_array);
}

// Split

char	**ft_split(char const *s, char c)
{
	struct StringExtractor	se;
	struct SplitArray		split_array;

	se = string_extractor_init(s);
	split_array = split_array_init();
	while (is_end(se) == 0)
	{
		char *substring = extract(&se, c);
		if (substring)
		{
			add_to_split_array(&split_array, substring);
		}
	}
	add_null_to_split_array(&split_array);

	return (split_array.array);
}

