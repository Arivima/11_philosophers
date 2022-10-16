/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:14:29 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:07:25 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (src[i] != 0)
	{
		if (i + 1 < size)
			dst[i] = src[i];
		if (i + 1 == size)
			dst[i] = 0;
		i++;
	}
	if (i + 1 <= size)
		dst[i] = 0;
	return (i);
}
