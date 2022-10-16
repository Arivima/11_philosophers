/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:57:25 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/10 18:04:13 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp;
	char	*needlestart;
	size_t	t;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (0);
	needlestart = (char *)needle;
	while (len)
	{
		temp = (char *)haystack;
		t = len;
		while (t-- && *haystack && *haystack == *needle)
		{
			haystack++;
			needle++;
			if (!*needle)
				return (temp);
		}
		haystack = temp + 1;
		needle = needlestart;
		len--;
	}
	return (NULL);
}
