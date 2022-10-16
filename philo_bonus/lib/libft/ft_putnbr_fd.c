/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:55:55 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/12 16:34:40 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int		long_n;

	if (n < 0)
	{
		long_n = -(long int)n;
		write(fd, "-", 1);
	}
	else
		long_n = n;
	if (long_n > 9)
	{
		ft_putnbr_fd(long_n / 10, fd);
		ft_putchar_fd((long_n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(long_n + '0', fd);
}
