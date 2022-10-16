/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:11:03 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:11:05 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_philosophers(t_philo **head, int n, t_hold *hold)
{
	t_philo		*philo;

	if (create_elem_list(head, &philo) == ERR)
		return (ERR);
	philo->process_id = 0;
	philo->t_start = 0;
	philo->t_last_meal = 0;
	philo->n_eat = 0;
	philo->f_done_eating = 0;
	philo->f_death = 0;
	if (n == 1)
		philo->is_last = 1;
	else
		philo->is_last = 0;
	philo->hold = hold;
	return (0);
}
	// printf("# create_philosophers %d ok\n", philo->philo_id);

int	create_elem_list(t_philo **head, t_philo **elem)
{
	t_philo		*tail;
	t_philo		*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		return (ft_error("ft_create_philosophers malloc"));
	ft_memset(philo, '\0', sizeof(t_philo));
	philo->next = NULL;
	tail = go_to_end(head);
	if (!tail)
	{
		*head = philo;
		philo->philo_id = 1;
		philo->prev = NULL;
	}
	else
	{
		tail->next = philo;
		philo->prev = tail;
		philo->philo_id = tail->philo_id + 1;
	}
	*elem = philo;
	return (0);
}

t_philo	*go_to_end(t_philo **head)
{
	t_philo		*tail;

	tail = *head;
	if (!tail)
		return (NULL);
	while (tail->next)
		tail = tail->next;
	return (tail);
}

t_philo	*go_to_top(t_philo **head)
{
	t_philo		*tail;

	tail = *head;
	if (!tail)
		return (NULL);
	while (tail->prev)
		tail = tail->prev;
	return (tail);
}
