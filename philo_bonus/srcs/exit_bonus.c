/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:24:12 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:24:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_exit(t_hold *hold, int status)
{
	ft_kill_philo(hold);
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
	// if (ft_sem_close_unlink(hold) == ERR)
	// 	status = EXIT_FAILURE;

int	ft_free(t_hold *hold)
{
	t_philo	*tmp;

	if (hold && hold->head)
	{
		tmp = hold->head;
		while (tmp)
		{
			hold->head = tmp;
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

int	ft_sem_close_unlink(t_hold *hold)
{
	if (ft_sem_close_unlink_each(hold->sem_write, SEM_WRITE) == ERR)
		return (ERR);
	if (ft_sem_close_unlink_each(hold->sem_forks, SEM_FORKS) == ERR)
		return (ERR);
	if (ft_sem_close_unlink_each(hold->sem_end_die, SEM_END_DIE) == ERR)
		return (ERR);
	if (ft_sem_close_unlink_each(hold->sem_end_eat, SEM_END_EAT) == ERR)
		return (ERR);
	return (0);
}

int	ft_sem_close_unlink_each(sem_t *sem, char *name)
{
	if (sem_close(sem) == ERR)
		ft_error("sem close");
	if (sem_unlink(name))
		ft_error("sem unlink");
	return (0);
}

int	ft_print_at_exit(t_hold *hold, int *status)
{
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
	}
	return (0);
}
