/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:24 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/03 13:20:05 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_len;
	size_t	i;
	char	*trimmed_str;

	i = 0;
	trimmed_str = (char *)ft_calloc(new_len + 1, sizeof(char));
	new_len = end - start;
	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;
	if (!trimmed_str)
		return (NULL);
	while (i < new_len)
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	return (trimmed_str);
}
