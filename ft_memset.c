/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:36 by lgrigore          #+#    #+#             */
/*   Updated: 2025/01/31 13:16:14 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *v, int c, size_t s)
{
	char	*str;

	str = v;
	while (s > 0)
	{
		str[s] = c;
		s--;
	}
	return (v);
}
