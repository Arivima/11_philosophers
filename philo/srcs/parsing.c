/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:34:51 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:34:52 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	hold->t_start = get_time();
	hold->f_write = 0;
	hold->f_die = 0;
	hold->f_end_simulation = 0;
	hold->f_done_eating = 0;
	hold->f_death = 0;
	hold->f_exit = 0;
	hold->f_error = 0;
	hold->f_thread_start = 0;
	hold->head = NULL;
	return (0);
}

int	init_mutex_holder(t_hold *hold)
{
	if (pthread_mutex_init(&hold->m_write, NULL))
		return (ERR);
	hold->f_write = -1;
	if (pthread_mutex_init(&hold->m_die, NULL))
		return (ERR);
	hold->f_die = -1;
	if (pthread_mutex_init(&hold->m_end_simulation, NULL))
		return (ERR);
	hold->f_end_simulation = -1;
	return (0);
}
