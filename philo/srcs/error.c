/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:34:32 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:34:34 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_hold(t_hold *hold, char *msg)
{
	if (hold)
		hold->f_error = 1;
	ft_error(msg);
	return (ERR);
}

int	ft_error( char *msg)
{
	ft_putstr_fd(NAME": ", 2);
	ft_putstr_fd("error", 2);
	if (msg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n", 2);
	return (ERR);
}
