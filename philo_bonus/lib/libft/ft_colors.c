/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:58:14 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/09 15:58:16 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BLACK (0x00000000)
#define WHITE (0x00FFFFFF)
#define RED (0x00FF0000)
#define GREEN (0x00008000)
#define YELLOW (0x00FFFF00)
#define BLUE (0x000000FF)

int	ft_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
