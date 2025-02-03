/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:36 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/03 12:59:27 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *v, int c, size_t s)
{
	unsigned char	*str;

	if (!v)
	{
		return (NULL);
	}
	str = (unsigned char *)v;
	while (s--)
	{
		*str++ = (unsigned char)c;
	}
	return (v);
}
