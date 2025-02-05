/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:21:18 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 21:29:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
	{
		return (NULL);
	}
	if (start > ft_strlen(s))
	{
		len = 0;
	}
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
