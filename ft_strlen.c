/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:20:56 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 12:48:50 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	num;

	num = 0;
	/*if (s == NULL)
	{
		return (0);
	}*/
	while (s[num] != '\0')
	{
		num++;
	}
	return (num);
}
