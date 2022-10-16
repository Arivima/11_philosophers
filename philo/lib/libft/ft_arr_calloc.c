/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:42:15 by avilla-m          #+#    #+#             */
/*   Updated: 2022/03/18 15:42:17 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_calloc(int rows, int cols)
{
	int		i;
	char	**array;

	array = (char **) malloc(sizeof(char *) * (rows + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = ft_calloc(cols + 1, sizeof(char));
		if (!array[i])
			return (NULL);
		i++;
	}
	array[i] = NULL;
	return (array);
}
