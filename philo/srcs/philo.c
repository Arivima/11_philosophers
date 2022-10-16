/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:34:59 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:35:01 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exec_philosopher(t_philo *philo)
{
	philo->hold->f_thread_start++;
	philo->t_last_meal = get_time();
	philo->t_start = get_time();
	while (!philo->hold->f_death && !philo->hold->f_error)
	{
		if (philo_alone(philo) == ERR)
			return (ERR);
		if (philo_eat(philo) == ERR)
			return (ERR);
		if ((philo->hold->n_min_eat >= 0 \
		&& philo->n_eat == philo->hold->n_min_eat))
		{
			if (is_done_eating(philo) == ERR)
				return (ERR);
			return (0);
		}
		if (philo_sleep(philo) == ERR || philo_think(philo) == ERR)
			return (ERR);
		ft_usleep(1);
	}
	return (0);
}

int	philo_alone(t_philo *philo)
{
	if (philo->hold->n_philo == 1)
	{
		print_log_line(philo, "has taken a fork");
		ft_usleep(philo->hold->t_to_die);
		print_log_line(philo, "has died");
		return (ERR);
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	if (philo->hold->f_death || philo->hold->f_error)
		return (ERR);
	if ((get_time() - philo->t_last_meal) > philo->hold->t_to_die)
	{
		if (pthread_mutex_lock(&philo->hold->m_die))
			return (ft_error_hold(philo->hold, "pthread_mutex_lock\nEXIT"));
		if (!philo->hold->f_death && !philo->hold->f_error)
		{
			philo->hold->f_die = 1;
			philo->hold->f_death = 1;
			philo->f_death = 1;
			pthread_mutex_lock(&philo->hold->m_write);
			philo->hold->f_write = 1;
			print_log_line(philo, "has died");
			ft_usleep(philo->hold->t_to_die);
			pthread_mutex_unlock(&philo->hold->m_write);
			philo->hold->f_write = -1;
		}
		if (pthread_mutex_unlock(&philo->hold->m_die))
			return (ft_error_hold(philo->hold, "pthread_mutex_unlock\nEXIT"));
		philo->hold->f_die = -1;
		return (ERR);
	}
	return (0);
}

int	is_done_eating(t_philo *philo)
{
	if (is_dead(philo) == ERR)
		return (ERR);
	if (pthread_mutex_lock(&philo->hold->m_end_simulation))
		return (ft_error_hold(philo->hold, \
		"exec_philosopher: pthread_mutex_lock\nEXIT thread"));
	philo->hold->f_end_simulation = 1;
	philo->hold->f_done_eating++;
	philo->f_done_eating = 1;
	if (pthread_mutex_unlock(&philo->hold->m_end_simulation))
		return (ft_error_hold(philo->hold, \
		"exec_philosopher: pthread_mutex_unlock\nEXIT thread"));
	philo->hold->f_end_simulation = -1;
	return (0);
}
