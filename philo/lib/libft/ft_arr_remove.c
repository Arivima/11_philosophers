/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:42:51 by avilla-m          #+#    #+#             */
/*   Updated: 2022/03/18 15:42:53 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_remove(char **old_arr, int row)
{
	int		i;
	char	**new_arr;

	i = 0;
	while (old_arr[i])
		i++;
	if (row >= i || row < 0)
		return (old_arr);
	new_arr = (char **) malloc(sizeof(char *) * i);
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < row)
	{
		new_arr[i] = ft_strdup(old_arr[i]);
		i++;
	}
	while (old_arr[i + 1])
	{
		new_arr[i] = ft_strdup(old_arr[i + 1]);
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}
