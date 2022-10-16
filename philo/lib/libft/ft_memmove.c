/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:55:50 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/08 12:43:57 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest;
	const unsigned char		*source;

	dest = dst;
	source = src;
	if (!dst && !src)
		return (0);
	while (len--)
	{
		if (source < dest)
			dest[len] = source[len];
		else
			*dest++ = *source++;
	}
	return (dst);
}
