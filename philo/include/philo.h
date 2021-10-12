/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:34:54 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/06 14:28:59 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef enum e_status
{
	alive,
	dead
}			t_status;

typedef struct s_data
{
	int				philo_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	long long		t_launch;
	t_status		status;
	int				*list;
}					t_data;

typedef struct s_philo
{
	int				id;
	t_data			*data;
	long long		t_last_meal;
	int				num_eaten;
}					t_philo;

/* main.c */
int				main(int argc, char **argv);
int				check_args(int argc, char **argv);
int				create_threads(t_philo *philo);
t_status		check_status(t_philo *philo);

/* routine.c */
void			*routine(void *void_philo);
void			taking_fork(t_philo *philo);
void			eating(t_philo *philo);

/* init.c */
t_data			*init_data(int argc, char **argv);
t_philo			*init_philos(int argc, char **argv);
int				*init_list(t_data *data);
pthread_mutex_t	*init_forks(t_data *data);
void			update_list(t_data *data, int philo_id);

/* utils.c */
int				ft_atoi(const char *nptr);
long long		get_time_in_ms(void);
void			smart_sleep(long long time, t_philo *philo);
void			print_status(t_philo *philo, char *str);
void			print_dead(t_philo *philo);

#endif
