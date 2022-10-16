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

int	philo_eat(t_philo *philo)
{
	int	status;

	if (philo_take_fork(philo, &status) == ERR)
		return (ERR);
	if (philo->f_death == ALIVE && (philo->n_fourchettes == 2))
	{
		philo->n_eat++;
		philo->t_last_meal = get_time();
		status = is_dead(philo);
		if (philo->f_death == ALIVE)
		{
			if (write_log(philo, "is eating") != ERR)
				ft_usleep(philo->hold->t_to_eat);
		}
		else
			status = TWO_FORK;
	}
	if (philo_free_fork(philo, &status) == ERR)
		return (ERR);
	if (philo->f_death == DEAD)
		return (ERR);
	return (0);
}

int	philo_take_fork(t_philo *philo, int *status)
{
	t_philo	*head;

	head = go_to_top(&philo);
	if (philo_wait_turn(philo) == ERR || philo_wait_fork(philo, head) == ERR)
		return (ERR);
	if (is_dead(philo) == ERR)
		return (ERR);
	if (!philo->is_last && philo->next \
	&& taking_fork(philo, philo->next) == ERR)
		return (ERR);
	else if (philo->is_last && philo != head && taking_fork(philo, head) == ERR)
		return (ERR);
	*status = is_dead(philo);
	if (philo->f_death == DEAD)
		*status = ONE_FORK;
	if (philo->f_death == ALIVE && taking_fork(philo, philo) == ERR)
		return (ERR);
	return (0);
}

int	philo_wait_fork(t_philo *philo, t_philo *head)
{
	while (philo->f_fourchette == 1 \
	|| ((!philo->is_last && philo->next && philo->next->f_fourchette == 1) \
	|| (philo->is_last && philo != head && head->f_fourchette == 1)))
	{
		if (is_dead(philo) == ERR)
			return (ERR);
		ft_usleep(1);
	}
	return (0);
}

int	philo_wait_turn(t_philo *philo)
{
	if (!philo->n_eat && philo->philo_id % 2)
		ft_usleep(philo->hold->t_to_eat);
	while (philo->n_eat && (get_time() - \
	philo->t_last_meal < philo->hold->t_to_eat))
	{
		if (is_dead(philo) == ERR)
			return (ERR);
		ft_usleep(1);
	}
	return (0);
}

int	taking_fork(t_philo *philo, t_philo *fourchette)
{
	if (pthread_mutex_lock(&fourchette->m_fourchette))
		return (ft_error_hold(philo->hold, \
		"philo_take_fork: pthread_mutex_lock\nEXIT thread"));
	fourchette->f_fourchette = 1;
	philo->n_fourchettes += 1;
	write_log(philo, "has taken a fork");
	return (0);
}
