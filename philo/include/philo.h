/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:35:32 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 15:35:34 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// includes
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

// structures
typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	int				is_last;
	int				f_fourchette;
	pthread_mutex_t	m_fourchette;
	int				t_start;
	int				t_last_meal;
	int				n_eat;
	int				n_fourchettes;
	int				f_done_eating;
	int				f_death;
	struct s_philo	*prev;
	struct s_philo	*next;
	struct s_hold	*hold;
}				t_philo;

typedef struct s_hold
{
	int				n_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_min_eat;
	int				t_start;
	int				f_write;
	pthread_mutex_t	m_write;
	int				f_die;
	pthread_mutex_t	m_die;
	int				f_end_simulation;
	pthread_mutex_t	m_end_simulation;
	int				f_done_eating;
	int				f_death;
	int				f_exit;
	int				f_error;
	int				f_thread_start;
	t_philo			*head;
}				t_hold;

// definitions
# define NAME "Philosophers"
# define ERR -1
# define ONE_FORK 1
# define TWO_FORK 2
# define ALIVE 0
# define DEAD 1

// prototypes
// main
int		philosophers(t_hold *hold);
int		create_threads(t_hold *hold);
int		join_threads(t_hold *hold);

// parsing
int		protections(char **av);
int		parsing_init(t_hold *hold, char **av);
int		init_mutex_holder(t_hold *hold);

// Philo
int		exec_philosopher(t_philo *philo);
int		is_dead(t_philo *philo);
int		is_done_eating(t_philo *philo);
int		philo_alone(t_philo *philo);

// activities
int		philo_eat(t_philo *philo);
int		philo_take_fork(t_philo *philo, int *status);
int		philo_wait_fork(t_philo *philo, t_philo *head);
int		philo_wait_turn(t_philo *philo);
int		taking_fork(t_philo *philo, t_philo *fourchette);

int		freeing_fork(t_philo *philo, t_philo *fourchette);
int		philo_free_fork(t_philo *philo, int *status);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);

// philo utils
int		get_time(void);
void	ft_usleep(u_int64_t time_in_ms);
int		write_log(t_philo *philo, char *activity);
int		print_log_line(t_philo *philo, char *activity);

// list utils
int		create_philosophers(t_philo **head, int n, t_hold *hold);
int		create_elem_list(t_philo **head, t_philo **elem);
t_philo	*go_to_top(t_philo **head);
t_philo	*go_to_end(t_philo **head);

// error
int		ft_error(char *msg);
int		ft_error_hold(t_hold *hold, char *msg);

// exit
int		ft_exit(t_hold *hold, int status);
int		ft_free(t_hold *hold);
int		ft_free_philo(t_hold *hold);
int		ft_print_at_exit(t_hold *hold, int *status);
int		print_time_eaten(t_philo *philo);

#endif

// int		is_all_threads_created(t_hold *hold);
// testing
// int		print_philo(t_philo *head);
// int		print_holder(t_hold *hold);
// int		print_philo_alone(t_philo *tmp);