/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:35:19 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:35:21 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	static struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * (u_int64_t)1000) + (tm.tv_usec / 1000));
}

void	ft_usleep(u_int64_t time_in_ms)
{
	u_int64_t	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

int	write_log(t_philo *philo, char *activity)
{
	if ((get_time() - philo->t_last_meal) > philo->hold->t_to_die \
	|| philo->hold->f_death == 1 || philo->hold->f_error)
		return (ERR);
	if (pthread_mutex_lock(&philo->hold->m_write))
		return (ft_error_hold(philo->hold, \
		"write_log: pthread_mutex_lock\nEXIT thread"));
	philo->hold->f_write = 1;
	if (!philo->hold->f_death && !philo->hold->f_error \
	&& ((get_time() - philo->t_last_meal) <= philo->hold->t_to_die))
		print_log_line(philo, activity);
	if (pthread_mutex_unlock(&philo->hold->m_write))
		return (ft_error_hold(philo->hold, \
		"write_log: pthread_mutex_unlock\nEXIT thread"));
	philo->hold->f_write = -1;
	return (0);
}

int	print_log_line(t_philo *philo, char *activity)
{
	printf("[%5dms]\t", get_time() - philo->t_start);
	if (philo->hold->n_min_eat > 0 && (philo->n_eat >= philo->hold->n_min_eat))
		printf("[%2d ok]\t", philo->n_eat);
	else
		printf("[%2d   ]\t", philo->n_eat);
	printf("Philosopher %2d\t", philo->philo_id);
	printf("[%5d]\t[%5d]\t", (get_time() - philo->t_last_meal), \
	philo->hold->t_to_die - (get_time() - philo->t_last_meal));
	printf("%s\n", activity);
	return (0);
}
