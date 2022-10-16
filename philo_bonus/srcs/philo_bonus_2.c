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

int	monitor_check_death(t_philo *philo)
{
	while (1)
	{
		if ((get_time() - philo->t_last_meal) > philo->hold->t_to_die)
		{
			philo->f_death = 1;
			if (sem_wait(philo->hold->sem_write) == ERR)
				return (ft_error_hold(philo->hold, "sem_wait: sem_write"));
			print_log_line(philo, "has died");
			printf("\nEND OF LOG\n");
			printf("------------------------------------------------------\n");
			if (sem_post(philo->hold->sem_end_die) == ERR)
				return (ft_error_hold(philo->hold, "sem_wait: sem_end_die"));
			return (ft_exit_child(philo, EXIT_SUCCESS));
		}
		else if (!philo->f_done_eating \
		&& philo->n_eat == philo->hold->n_min_eat)
		{
			if (sem_post(philo->hold->sem_end_eat) == ERR)
				return (ft_error_hold(philo->hold, "sem_post: sem_end_eat"));
			philo->f_done_eating = 1;
		}
		ft_usleep(1);
	}
	return (0);
}
	// printf("///MONITOR %d: Ready to watch philo\n", philo->philo_id);
			// printf("///MONITOR %d: waiting to wr die\n", philo->philo_id);

int	monitor_end_eaten_enough(t_hold *hold)
{
	int		i;

	i = hold->n_philo;
	while (i--)
	{
		if (sem_wait(hold->sem_end_eat) == ERR)
			return (ft_error_hold(hold, "sem_wait: sem_end_eat"));
	}
	if (sem_wait(hold->sem_write) == ERR)
		return (ft_error_hold(hold, "sem_wait: sem_write"));
	printf("\nEND OF LOG\n");
	printf("--------------------------------------------------------------\n");
	ft_wait_all_proc_created(hold);
	ft_kill_philo(hold);
	hold->f_done_eating = 1;
	return (EXIT_SUCCESS);
}
// printf("//MONITOR 01_EAT: Ready to close when philo have eaten enough\n");
// printf("//MONITOR 01_EAT: %d philo left\n", i);
// printf("//MONITOR 01_EAT: all philo have eaten enough, return to main\n");

int	monitor_end_death(t_hold *hold)
{
	if (sem_wait(hold->sem_end_die) == ERR)
		return (ft_error_hold(hold, "sem_wait: sem_end_death"));
	ft_wait_all_proc_created(hold);
	ft_kill_philo(hold);
	hold->f_death = 1;
	return (EXIT_SUCCESS);
}
	// printf("//MONITOR 02_DIE: Ready to close when one philo dies\n");
	// printf("//MONITOR 02_DIE: one philo died, return to main\n");

int	ft_kill_philo(t_hold *hold)
{
	t_philo		*philo;

	philo = hold->head;
	while (philo)
	{
		if (philo->process_id)
		{
			kill(philo->process_id, SIGKILL);
			ft_memset(&philo->process_id, '\0', sizeof(philo->process_id));
		}
		if (philo->next)
			philo = philo->next;
		else
			break ;
	}
	return (0);
}
			// printf("# Killed Philo %d | process id %d\n", 
			//\	philo->philo_id, philo->process_id);
