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

void	ft_putnbr_base(int nbr, int base)
{
	char	*ref_base;

	ref_base = "0123456789ABCDEF";
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base);
		ft_putnbr_base(nbr % base, base);
	}
	else
		write(1, &ref_base[nbr], 1);
}
