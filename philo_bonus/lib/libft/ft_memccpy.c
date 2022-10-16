/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:14:36 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/08 12:37:59 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	source = src;
	dest = dst;
	while (n--)
	{
		*dest++ = *source++;
		if ((unsigned char)c == *(source - 1))
			return (dest);
	}
	return (NULL);
}
