/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:48:58 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 21:42:24 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];
	int		i;
	int		negative;

	i = 11;
	negative = (n < 0);
	buffer[i] = '\0';
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (negative)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		n = -n;
	}
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
	{
		buffer[--i] = '-';
	}
	write(fd, &buffer[i], 11 - i);
}
