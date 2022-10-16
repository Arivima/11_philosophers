/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:19:59 by avilla-m          #+#    #+#             */
/*   Updated: 2022/03/22 17:00:03 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (!*s1 || *s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_super_strncmp(const char *s1, const char *s2)
{
	if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0 \
	&& ft_strlen(s1) == ft_strlen(s2))
		return (0);
	return (1);
}
