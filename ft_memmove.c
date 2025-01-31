/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:13:38 by lgrigore          #+#    #+#             */
/*   Updated: 2025/01/31 13:15:20 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TO DO:: hacer que int sea size_t
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if ((s < d) && (n > 0))
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
