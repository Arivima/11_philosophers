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

int	ft_exit(t_hold *hold, int status)
{
	if (ft_print_at_exit(hold, &status) == ERR)
		status = EXIT_FAILURE;
	if (ft_free(hold) == ERR)
		status = EXIT_FAILURE;
	if (status == EXIT_SUCCESS)
		printf("\n>> Program exited successfully\n");
	else
		printf("\n>> Program failed\n");
	printf("--------------------------------------------------------------\n");
	exit(status);
	return (status * -1);
}

int	ft_free(t_hold *hold)
{
	if (ft_free_philo(hold) == ERR)
		return (ERR);
	if (hold->f_write == 1 || hold->f_die == 1 || hold->f_end_simulation == 1)
		return (ft_error("ft_exit: pthread_mutex not unlocked"));
	if (hold && (hold->f_write == -1) && pthread_mutex_destroy(&hold->m_write))
		return (ft_error("ft_exit: pthread_mutex_destroy"));
	else if (hold && (hold->f_die == -1) && pthread_mutex_destroy(&hold->m_die))
		return (ft_error("ft_exit: pthread_mutex_destroy"));
	else if (hold && (hold->f_end_simulation == -1) \
	&& pthread_mutex_destroy(&hold->m_end_simulation))
		return (ft_error("ft_exit: pthread_mutex_destroy"));
	return (0);
}

int	ft_free_philo(t_hold *hold)
{
	t_philo	*tmp;

	if (hold && hold->head)
	{
		tmp = hold->head;
		while (tmp)
		{
			hold->head = tmp;
			if (hold->head->f_fourchette == 1)
				ft_error("ft_exit: pthread_mutex f_fourchette not unlocked");
			if ((hold->head->f_fourchette == -1) \
			&& pthread_mutex_destroy(&hold->head->m_fourchette))
				return (ft_error("ft_exit: pthread_mutex_destroy"));
			if (hold->head->next)
				tmp = hold->head->next;
			else
				tmp = NULL;
			free(hold->head);
			hold->head = NULL;
		}
	}
	return (0);
}
	// if (hold->f_write == 1)
	// 	ft_error("ft_exit: pthread_mutex f_write not unlocked");
	// if (hold->f_die == 1)
	// 	ft_error("ft_exit: pthread_mutex f_die not unlocked");
	// if (hold->f_end_simulation == 1)
	// 	ft_error("ft_exit: pthread_mutex f_end_simulation not unlocked");

int	ft_print_at_exit(t_hold *hold, int *status)
{
	printf("--------------------------------------------------------------\n");
	printf("Exit.\n");
	if (!hold)
		return (ft_error("ft_exit"));
	if (*status == EXIT_SUCCESS)
	{
		if (hold->f_death)
			printf(">> Simulation ended because a philo died\n");
		else
			printf(">> Simulation ended because philo have eaten enough\n");
	}
	if (hold->n_philo && hold->t_to_die && hold->t_to_eat && hold->t_to_sleep)
	{
		printf("\nFor correction\n");
		printf("Arguments: ");
		printf("[%d] Philosophers, ", hold->n_philo);
		printf("[%d] time to die, ", hold->t_to_die);
		printf("[%d] time to eat, ", hold->t_to_eat);
		printf("[%d] time to sleep, ", hold->t_to_sleep);
		printf("[%d] min nb eat\n", hold->n_min_eat);
		if ((hold->f_thread_start == hold->n_philo) && hold->head)
			print_time_eaten(hold->head);
	}
	return (0);
}

int	print_time_eaten(t_philo *philo)
{
	while (philo)
	{
		printf("Philosopher %d has eaten %d times\n", \
		philo->philo_id, philo->n_eat);
		if (philo->next)
			philo = philo->next;
		else
			break ;
	}
	return (0);
}
