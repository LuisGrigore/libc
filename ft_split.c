/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:23 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/02 15:25:25 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

struct SplitArray		*add_to_split_array(struct SplitArray *split_array,
							char *str);
void					add_null_to_split_array(struct SplitArray *split_array);
struct SplitArray		split_array_init(void);
struct StringExtractor	string_extractor_init(const char *str);
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

char	*extract(struct StringExtractor *se, char regx)
{
	char	*res;
	size_t	len;

	while (se->str[se->j] == regx && se->str[se->j] != '\0')
	{
		se->j++;
		se->i = se->j;
	}
	while (se->str[se->j] != regx && se->str[se->j] != '\0')
	{
		se->j++;
	}
	len = (size_t)(se->j - se->i);
	res = ft_substr(se->str, se->i, len);
	return (res);
}

// Split_Array

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

// Split

char	**ft_split(char const *s, char c)
{
	struct StringExtractor	se;
	struct SplitArray		split_array;
	char					*substring;
	if (!s || *s == '\0')  // Verifica si s es NULL o una cadena vacía
        return NULL;
	se = string_extractor_init(s);
	split_array.array = NULL;
	split_array.size = 0;
	while (se.str[se.j] != '\0')
	{
		substring = extract(&se, c);
		if (substring)
		{
			add_to_split_array(&split_array, substring);
		}
	}
	split_array.array = (char **)ft_realloc(split_array.array,
			(split_array.size + 1) * sizeof(char *));
	split_array.array[split_array.size] = NULL;
	split_array.last = &split_array.array[split_array.size];
	split_array.size++;
	return (split_array.array);
}
