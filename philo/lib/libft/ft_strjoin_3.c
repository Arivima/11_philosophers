/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:32:46 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:06:37 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	new = ft_strjoin(tmp, s3);
	free(tmp);
	tmp = NULL;
	if (!new)
		return (NULL);
	return (new);
}
