/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:48:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/01/30 18:02:04 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct SplitArray	*add_to_split_array(struct SplitArray *split_array,
				char *str);
void	add_null_to_split_array(struct SplitArray *split_array);
struct SplitArray	SplitArray();

struct StringExtractor	StringExtractor(const char * str);
int	is_end(struct StringExtractor se);
char	*extract(struct StringExtractor *se, char regx);


//String extractor
struct StringExtractor
{
	const char*	str;
	unsigned int	i;
	unsigned int	j;
};


struct StringExtractor	StringExtractor(const char * str)
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

    if (str == NULL || start >= end) {
        return NULL;
    }
    return (ft_substr(str, start, len));
}

void	trunc_regx(struct StringExtractor *se, char regx)
{
    while (se->str[se->j] == regx && se->str[se->j] != '\0')
    {
        se->j++;
        se->i = se->j;
    }
}

void	advance_j(struct StringExtractor *se, char regx)
{
    while(se->str[se->j] != regx && se->str[se->j] != '\0')
    {
        se->j++;
    }
}

char	*extract(struct StringExtractor *se, char regx)
{
    char	*res;

    trunc_regx(se, regx);
	
    advance_j(se, regx);

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

//Split_Array
struct SplitArray{
	char ** array;
	size_t size;
	char ** last;
};

void	free_array(char **array, int size)
{
	int	i;

	i = 0;

    while (i < size) {
        free(array[i]);
		i++;
    }
    free(array);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
    void	*new_ptr;

	new_ptr = malloc(new_size);

    if (!new_ptr) {
        return NULL;
    }
    new_ptr = ft_memmove(new_ptr, ptr, new_size);
    free(ptr);
    return (new_ptr);
}

struct	SplitArray *add_to_split_array(struct SplitArray *split_array, char *str)
{
    if (split_array->array == NULL) {
        split_array->array = (char **) malloc(sizeof(char *));
        split_array->array[0] = str;
    } else {
        split_array->array = (char **) ft_realloc(split_array->array, (split_array->size + 1) * sizeof(char *));
        split_array->array[split_array->size] = str;
    }
    split_array->size++;
    return (split_array);
}

void	add_null_to_split_array(struct SplitArray *split_array)
{
    split_array->array = (char **) ft_realloc(split_array->array, (split_array->size + 1) * sizeof(char *));
    
    split_array->array[split_array->size] = NULL;
	split_array->last = &split_array->array[split_array->size];
	split_array->size++;

}

struct SplitArray	SplitArray()
{
    struct SplitArray	split_array;
    split_array.array = NULL;
    split_array.size = 0;
    return (split_array);
}
//Split

char **ft_split(char const *s, char c)
{
	struct StringExtractor string_extractor;
	struct SplitArray split_array;

	string_extractor = StringExtractor(s);
	split_array = SplitArray();
	
	while(is_end(string_extractor) == 0)
	{
		add_to_split_array(&split_array, extract(&string_extractor,c));
	}
	add_null_to_split_array(&split_array);
	return split_array.array;
}


