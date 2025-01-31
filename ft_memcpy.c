/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:12:18 by lgrigore          #+#    #+#             */
/*   Updated: 2025/01/31 13:13:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (char)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
