/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:49:45 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 12:51:06 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	total_size = nmemb * size;
	ptr = malloc(total_size);
	/*if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);*/
	if (!ptr)
	{
		return (NULL);
	}
	byte_ptr = (unsigned char *)ptr;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tsize;

	tsize = nmemb * size;
	if (nmemb != 0 && tsize / nmemb != size)
		return (NULL);
	ptr = malloc(tsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, tsize);
	return (ptr);
}*/