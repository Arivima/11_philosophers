/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:35:11 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:35:13 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philosophers(t_philo **head, int n, t_hold *hold)
{
	t_philo		*philo;

	if (create_elem_list(head, &philo) == ERR)
		return (ERR);
	philo->f_done_eating = 0;
	philo->f_death = 0;
	philo->f_fourchette = 0;
	if (pthread_mutex_init(&philo->m_fourchette, NULL) != 0)
		return (ERR);
	philo->f_fourchette = -1;
	philo->n_eat = 0;
	philo->n_fourchettes = 0;
	philo->t_last_meal = 0;
	philo->t_start = 0;
	if (n == 1)
		philo->is_last = 1;
	else
		philo->is_last = 0;
	philo->hold = hold;
	return (0);
}
	// write_log(philo, "was born");

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
