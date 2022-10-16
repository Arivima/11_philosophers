/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:34:42 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:34:44 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_hold	hold;

	if (!(ac == 5 || ac == 6))
	{
		ft_error("Wrong number of arguments.");
		ft_exit(&hold, EXIT_FAILURE);
	}
	if (parsing_init(&hold, av) == ERR || init_mutex_holder(&hold) == ERR)
		return (ft_exit(&hold, EXIT_FAILURE));
	if (philosophers(&hold) == ERR)
		return (ft_exit(&hold, EXIT_FAILURE));
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
	if (join_threads(hold) == ERR)
		return (ERR);
	if (hold->f_done_eating == hold->n_philo || hold->f_death)
		return (ft_exit(hold, EXIT_SUCCESS));
	else
		return (ERR);
	return (0);
}

int	create_threads(t_hold *hold)
{
	t_philo		*philo;

	philo = hold->head;
	while (philo)
	{
		if (pthread_create(&philo->thread_id, \
		NULL, (void *) exec_philosopher, philo))
			return (ft_error_hold(hold, "pthread_create"));
		if (philo->next)
			philo = philo->next;
		else
			break ;
	}
	return (0);
}

int	join_threads(t_hold *hold)
{
	t_philo	*philo;

	if (hold->head)
	{
		philo = hold->head;
		while (philo)
		{
			if (philo->thread_id && pthread_join(philo->thread_id, NULL))
				return (ft_error_hold(hold, "phtread_join"));
			ft_memset(&philo->thread_id, '\0', sizeof(philo->thread_id));
			if (philo && philo->next)
				philo = philo->next;
			else
				break ;
		}
	}
	return (0);
}
