/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:16:48 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:09:49 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	check_start(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i++;
	}
	return (i);
}

unsigned int	check_end(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i && set[j])
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;
	unsigned int	end;
	char			*trim;

	if (!s1)
		return (0);
	if (!s1[0])
		return (ft_strdup(""));
	start = check_start(s1, set);
	end = check_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	trim = ft_substr(s1, start, len);
	return (trim);
}
