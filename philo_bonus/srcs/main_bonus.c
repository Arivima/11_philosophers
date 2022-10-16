/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:10:44 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:10:45 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_hold	hold;

	if (!(ac == 5 || ac == 6))
	{
		ft_error("Wrong number of arguments.");
		ft_exit(&hold, EXIT_FAILURE);
	}
	if (parsing_init(&hold, av) == ERR)
		ft_exit(&hold, EXIT_FAILURE);
	if (philosophers(&hold) == ERR)
		ft_exit(&hold, EXIT_FAILURE);
	ft_exit(&hold, EXIT_SUCCESS);
	return (0);
}

int	philosophers(t_hold *hold)
{
	int		i;

	i = hold->n_philo + 1;
	while (--i)
	{
		if (create_philosophers(&hold->head, i, hold) == ERR)
			return (ERR);
	}
	printf("\n[ time]\t[n_eat]\tPhilosopher  #\t[t_eat]\t[t_die]\tactivity\n");
	printf("--------------------------------------------------------------\n");
	if (create_threads(hold) == ERR)
		return (ERR);
	if (create_process(hold) == ERR)
		return (ERR);
	while (!hold->f_death && !hold->f_done_eating)
		ft_usleep(10);
	return (0);
}
	// printf("# Creating philosophers\n");
	// printf("\nSTART OF LOG\n\n");
	// printf("# Creating processes\n");
	// printf("# Program end\n");

int	create_threads(t_hold *hold)
{
	if (hold->n_min_eat > 0 \
	&& pthread_create(&hold->thread_id_01, NULL, (void *) \
	monitor_end_eaten_enough, hold) \
	&& pthread_detach(hold->thread_id_01))
		return (ft_error_hold(hold, "pthread_create || detach"));
	if (pthread_create(&hold->thread_id_02, NULL, (void *) \
	monitor_end_death, hold) && pthread_detach(hold->thread_id_02))
		return (ft_error_hold(hold, "pthread_create || detach"));
	ft_usleep(20);
	return (0);
}
	// if (hold->n_min_eat > 0)
	// 	printf("creating thread MONITOR EAT 01 && detaching\n");
	// printf("creating thread MONITOR DEATH 02 && detaching\n");

int	create_process(t_hold *hold)
{
	t_philo		*philo;

	philo = hold->head;
	set_pid(hold);
	while (philo)
	{
		philo->process_id = fork();
		if (philo->process_id == ERR)
			return (ft_error_hold(hold, "fork"));
		if (philo->process_id == CHILD)
		{
			if (child(philo) == ERR)
				return (ft_exit_child(philo, EXIT_FAILURE));
			ft_exit_child(philo, EXIT_SUCCESS);
		}
		if (philo->next)
			philo = philo->next;
		else
			break ;
	}
	return (0);
}
		// printf("# create_process %d\n", philo->philo_id);
		// printf("# (parent) philo %d process %d\n",
		//\ philo->philo_id, philo->process_id);

int	child(t_philo *philo)
{
	if (pthread_create(&philo->thread_id, NULL, \
	(void *) monitor_check_death, philo))
		return (ft_error("pthread_create"));
	ft_usleep(2);
	philo->t_start = get_time();
	philo->t_last_meal = get_time();
	if (exec_philosopher(philo) == ERR)
		return (ERR);
	return (0);
}
	// printf(">in child %d\n", philo->philo_id);
	// write_log(philo, "was born");
