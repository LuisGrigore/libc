/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:36 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/02 14:40:29 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *v, int c, size_t s)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)v;
	i = 0;
	while (i < s)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (v);
}
