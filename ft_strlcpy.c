/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:16:50 by lgrigore          #+#    #+#             */
/*   Updated: 2025/01/31 13:20:28 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;
	size_t		nleft;

	s = src;
	nleft = size;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			*dst++ = *src++;
			if (*dst == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - s - 1);
}
