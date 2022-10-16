/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_rows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:58:38 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/09 15:58:40 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arr_rows(char **arr)
{
	int	i;
	int	j;

	if (!arr)
		return (-1);
	i = 0;
	j = 0;
	while (arr[i])
	{
		if ((int) ft_strlen(arr[i]) > j)
			j = ft_strlen(arr[i]);
		i++;
	}
	return (j);
}
