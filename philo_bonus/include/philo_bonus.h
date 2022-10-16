/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:11:55 by avilla-m          #+#    #+#             */
/*   Updated: 2022/05/11 10:11:57 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// includes
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

// structures
typedef struct s_philo
{
	int				philo_id;
	pid_t			process_id;
	pthread_t		thread_id;
	int				is_last;
	int				t_start;
	int				t_last_meal;
	int				n_eat;
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
	pthread_t		thread_id_01;
	pthread_t		thread_id_02;
	sem_t			*sem_write;
	sem_t			*sem_end_die;
	sem_t			*sem_end_eat;
	sem_t			*sem_forks;
	int				f_done_eating;
	int				f_death;
	int				f_error;
	t_philo			*head;
}				t_hold;

// definitions
# define NAME "Philosophers"
# define ERR -1
# define ONE_FORK 1
# define TWO_FORK 2
# define ALIVE 0
# define DEAD 1
# define CHILD 0
# define SEM_WRITE "write"
# define SEM_FORKS "fourchettes"
# define SEM_END_DIE "end_die"
# define SEM_END_EAT "end_eat"

// prototypes
// main
int		philosophers(t_hold *hold);
int		create_threads(t_hold *hold);
int		create_process(t_hold *hold);
int		child(t_philo *philo);

// parsing_init
int		protections(char **av);
int		parsing_init(t_hold *hold, char **av);
int		init_sem_holder(t_hold *hold);

// parsing_list
int		create_philosophers(t_philo **head, int n, t_hold *hold);
int		create_elem_list(t_philo **head, t_philo **elem);
t_philo	*go_to_top(t_philo **head);
t_philo	*go_to_end(t_philo **head);

// philo
int		exec_philosopher(t_philo *philo);
int		is_eating(t_philo *philo);
int		is_dead(t_philo *philo);
int		set_pid(t_hold *hold);
int		ft_wait_all_proc_created(t_hold *hold);

int		monitor_check_death(t_philo *philo);
int		monitor_end_eaten_enough(t_hold *hold);
int		monitor_end_death(t_hold *hold);
int		ft_kill_philo(t_hold *hold);

// philo utils
int		get_time(void);
void	ft_usleep(u_int64_t time_in_ms);
int		write_log(t_philo *philo, char *activity);
int		print_log_line(t_philo *philo, char *activity);

// error
int		ft_error(char *msg);
int		ft_error_hold(t_hold *hold, char *msg);
int		ft_exit_child(t_philo *philo, int status);
// exit
int		ft_exit(t_hold *hold, int status);
int		ft_free(t_hold *hold);
int		ft_print_at_exit(t_hold *hold, int *status);
int		ft_sem_close_unlink(t_hold *hold);
int		ft_sem_close_unlink_each(sem_t *sem, char *name);

// testing
int		print_philo(t_philo *head);
int		print_holder(t_hold *hold);
int		print_philo_alone(t_philo *tmp);
// int		print_sem_value(char *sem_name, sem_t *sem);

#endif
