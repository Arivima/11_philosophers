/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_mtx_linecount.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:25 by avilla-m          #+#    #+#             */
/*   Updated: 2022/03/18 15:43:27 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_mtx_linecount(char **mtx)
{
	int	count;

	count = 0;
	while (mtx[count])
		count++;
	return (count);
}
