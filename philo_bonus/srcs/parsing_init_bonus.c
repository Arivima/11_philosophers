/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:10:54 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:10:56 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	protections(char **av)
{
	int			i;
	int			j;
	long int	n;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (ERR);
			j++;
		}
		if (ft_strlen(av[i]) > 10)
			return (ERR);
		n = ft_atoi(av[i]);
		if (n > 2147483647 || n <= 0)
			return (ERR);
		i++;
	}
	return (0);
}

int	parsing_init(t_hold *hold, char **av)
{
	ft_memset(hold, '\0', sizeof(t_hold));
	if (protections(av) == ERR)
		return (ft_error("Bad input"));
	hold->n_philo = ft_atoi(av[1]);
	hold->t_to_die = ft_atoi(av[2]);
	hold->t_to_eat = ft_atoi(av[3]);
	hold->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		hold->n_min_eat = ft_atoi(av[5]);
	else
		hold->n_min_eat = -1;
	hold->f_done_eating = 0;
	hold->f_death = 0;
	hold->f_error = 0;
	hold->head = NULL;
	if (init_sem_holder(hold) == ERR)
		return (ERR);
	return (0);
}
	// printf("# parsing init ok\n");

int	init_sem_holder(t_hold *hold)
{
	int	i;

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_END_DIE);
	sem_unlink(SEM_END_EAT);
	hold->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0644, hold->n_philo);
	hold->sem_write = sem_open(SEM_WRITE, O_CREAT, 0644, 1);
	hold->sem_end_die = sem_open(SEM_END_DIE, O_CREAT, 0644, 1);
	hold->sem_end_eat = sem_open(SEM_END_EAT, O_CREAT, 0644, hold->n_philo);
	if ((hold->sem_forks == SEM_FAILED) || (hold->sem_write == SEM_FAILED) \
	|| (hold->sem_end_eat == SEM_FAILED) || (hold->sem_end_die == SEM_FAILED))
		return (ft_error("sem_open"));
	if (sem_wait(hold->sem_end_die) == ERR)
		return (ft_error("sem_wait: "SEM_END_DIE));
	i = hold->n_philo;
	while (i--)
	{
		if (sem_wait(hold->sem_end_eat) == ERR)
			return (ft_error("sem_wait: "SEM_END_EAT));
	}
	return (0);
}
