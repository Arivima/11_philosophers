/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:33:23 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:22:35 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_c(char const *s, int j, char c)
{
	int	i;

	i = 0;
	while (s[j + i] != c && s[j + i])
		i++;
	return (i);
}

size_t	ft_flags(char const *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	while (*s)
	{
		flag = 0;
		while (*s != c && *s)
		{
			if (flag == 0)
			{
				flag = 1;
				i++;
			}
			s++;
		}
		if (flag == 0)
			s++;
	}
	return (i);
}

typedef struct s_split
{
	size_t		i;
	size_t		j;
	size_t		k;
}				t_split;

char	**ft_split(char const *s, char c)
{
	t_split		split;
	char		**table;

	if (!s)
		return (0);
	table = (char **)malloc((sizeof(char *) * (ft_flags(s, c) + 1)));
	if (!table)
		return (0);
	table[ft_flags(s, c)] = 0;
	split.i = 0;
	split.k = 0;
	split.j = 0;
	while (s[split.i])
	{
		while (s[split.i] == c && s[split.i])
			split.i++;
		if (s[split.i] != c && s[split.i])
		{
			split.k = ft_strlen_c(s, split.i, c);
			table[split.j++] = ft_substr(s, split.i, split.k);
			split.i += split.k;
		}
	}
	return (table);
}

// typedef struct s_split
// {
// 	size_t		i;
// 	size_t		j;
// 	size_t		k;
// }				t_split;

// size_t	ft_strlen_c(char const *s, int j, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[j + i] != c && s[j + i])
// 		i++;
// 	return (i);
// }

// size_t	ft_flags(char const *s, char c)
// {
// 	int	i;
// 	int	flag;

// 	i = 0;
// 	while (*s)
// 	{
// 		flag = 0;
// 		while (*s != c && *s)
// 		{
// 			if (flag == 0)
// 			{
// 				flag = 1;
// 				i++;
// 			}
// 			s++;
// 		}
// 		if (flag == 0)
// 			s++;
// 	}
// 	return (i);
// }

// char	**ft_split(char const *s, char c)
// {
// 	t_split		split;
// 	char		**table;

// 	if (!s)
// 		return (0);
// 	table = (char **)malloc((sizeof(char *) * (ft_flags(s, c)) + 1));
// 	if (!table)
// 		return (0);
// 	table[ft_flags(s, c)] = 0;
// 	split.i = 0;
// 	split.k = 0;
// 	split.j = 0;
// 	while (s[split.i])
// 	{
// 		while (s[split.i] == c && s[split.i])
// 			split.i++;
// 		if (s[split.i] != c && s[split.i])
// 		{
// 			split.k = ft_strlen_c(s, split.i, c);
// 			table[split.j++] = ft_substr(s, split.i, split.k);
// 			split.i += split.k;
// 		}
// 	}
// 	return (table);
// }
