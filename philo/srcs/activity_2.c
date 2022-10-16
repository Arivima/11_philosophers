/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:34:20 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:34:22 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	freeing_fork(t_philo *philo, t_philo *fourchette)
{
	if (pthread_mutex_unlock(&fourchette->m_fourchette))
		return (ft_error_hold(philo->hold, \
		"philo_free_fork: pthread_mutex_unlock\nEXIT thread"));
	fourchette->f_fourchette = -1;
	philo->n_fourchettes -= 1;
	return (0);
}
	// write_log(philo, "has freed a fork"); // testing

int	philo_free_fork(t_philo *philo, int *status)
{
	t_philo	*head;

	head = go_to_top(&philo);
	if ((*status != ONE_FORK) && freeing_fork(philo, philo) == ERR)
		return (ERR);
	if (!philo->is_last && freeing_fork(philo, philo->next) == ERR)
		return (ERR);
	else if (philo->is_last && (philo->hold->n_philo > 1) \
	&& freeing_fork(philo, head) == ERR)
		return (ERR);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (is_dead(philo) == ERR)
		return (ERR);
	if (write_log(philo, "is sleeping") != ERR)
		ft_usleep(philo->hold->t_to_sleep);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (is_dead(philo) == ERR)
		return (ERR);
	write_log(philo, "is thinking");
	return (0);
}
