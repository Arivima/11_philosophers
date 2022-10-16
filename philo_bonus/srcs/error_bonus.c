/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:10:34 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:10:36 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_error_hold(t_hold *hold, char *msg)
{
	if (hold)
		hold->f_error = 1;
	ft_error(msg);
	return (ERR);
}

int	ft_error(char *msg)
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

int	ft_exit_child(t_philo *philo, int status)
{
	if (status == EXIT_SUCCESS)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf(">>Child %d | %d failed\n", philo->philo_id, philo->process_id);
		exit(EXIT_FAILURE);
	}
	return (0);
}
	// printf("Exiting Child process %d.\n", philo->process_id);
		// printf(">> Child %d | %d exited successfully\n"
		//\, philo->philo_id, philo->process_id);
