/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:42:31 by avilla-m          #+#    #+#             */
/*   Updated: 2022/03/18 15:42:34 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_cpy(char **old)
{
	char	**new;
	int		i;

	i = 0;
	while (old && old[i])
		i++;
	new = ft_calloc(i + 1, sizeof(*new));
	i = 0;
	while (old && old[i])
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	return (new);
}
