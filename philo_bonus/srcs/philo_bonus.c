/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:11:12 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:11:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	exec_philosopher(t_philo *philo)
{
	while (!is_dead(philo))
	{
		if (!philo->n_eat && philo->philo_id % 2)
			ft_usleep(philo->hold->t_to_eat);
		if (is_eating(philo) == ERR)
			return (ERR);
		write_log(philo, "is sleeping");
		ft_usleep(philo->hold->t_to_sleep);
		write_log(philo, "is thinking");
	}
	while (1)
		ft_usleep(10);
}

int	is_eating(t_philo *philo)
{
	if (!is_dead(philo) && sem_wait(philo->hold->sem_forks) == ERR)
		return (ft_error_hold(philo->hold, "sem_wait: "SEM_FORKS));
	write_log(philo, "has taken left fork");
	if (!is_dead(philo) && sem_wait(philo->hold->sem_forks) == ERR)
		return (ft_error_hold(philo->hold, "sem_wait: "SEM_FORKS));
	write_log(philo, "has taken right fork");
	philo->n_eat++;
	write_log(philo, "is eating");
	if (!is_dead(philo))
		philo->t_last_meal = get_time();
	ft_usleep(philo->hold->t_to_eat);
	if (!is_dead(philo) && sem_post(philo->hold->sem_forks) == ERR)
		return (ft_error_hold(philo->hold, "sem_post: SEM_FORKS"));
	write_log(philo, "has freed left fork");
	if (!is_dead(philo) && sem_post(philo->hold->sem_forks) == ERR)
		return (ft_error_hold(philo->hold, "sem_post: SEM_FORKS"));
	write_log(philo, "has freed right fork");
	return (0);
}

int	is_dead(t_philo *philo)
{
	if (philo->f_death)
		return (ERR);
	if ((get_time() - philo->t_last_meal) > philo->hold->t_to_die)
		return (ERR);
	return (0);
}

int	set_pid(t_hold *hold)
{
	t_philo		*philo;

	philo = hold->head;
	while (philo)
	{
		philo->process_id = 1;
		if (philo->next)
			philo = philo->next;
		else
			break ;
	}
	return (0);
}
	// printf("# all process set to 1\n");

int	ft_wait_all_proc_created(t_hold *hold)
{
	t_philo		*philo;

	philo = hold->head;
	while (philo)
	{
		while (philo->process_id == 1)
		{
			ft_usleep(1);
		}
		if (philo->next)
			philo = philo->next;
		else
			break ;
	}
	return (0);
}
// printf("# waiting philo %d proc %d\n", philo->philo_id, philo->process_id);
// printf("# waited all process\n");
