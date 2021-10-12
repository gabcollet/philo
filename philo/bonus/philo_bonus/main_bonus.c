/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:34:41 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/06 11:34:21 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_status	check_status(t_philo *philo)
{
	long long	time_in_ms;

	time_in_ms = get_time_in_ms();
	if (philo->t_last_meal == 0)
		philo->t_last_meal = get_time_in_ms() - 1;
	if (philo->data->status == dead)
		return (dead);
	if (time_in_ms - philo->t_last_meal > philo->data->t_die)
	{
		print_dead(philo);
		return (dead);
	}
	return (alive);
}

int	check_args(int argc, char **argv)
{
	if (argc >= 4 && argc <= 6)
	{
		if (ft_atoi(argv[1]) < 1)
			return (printf("There must be at least 1 philosopher.\n"));
		if (ft_atoi(argv[2]) < 1)
			return (printf("Time_to_die must be at least 1.\n"));
		if (ft_atoi(argv[3]) < 1)
			return (printf("Time_to_eat must be at least 1.\n"));
		if (ft_atoi(argv[4]) < 1)
			return (printf("Time_to_sleep must be at least 1.\n"));
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			return (printf("Number_of_times_each_philosopher_must_eat must be \
at least 1.\n"));
	}
	else
		return (printf("ARGS NEEDED :	[number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep]\nOPTIONAL :	\
[number_of_times_each_philosopher_must_eat]\n"));
	return (0);
}

void	*all_have_eat(void *void_philo)
{
	t_philo	*philo;
	int		full;

	philo = void_philo;
	full = 0;
	while (full < philo->data->num_eat * philo->data->philo_num)
	{
		sem_wait(philo->data->sem_eaten);
		full++;
	}
	sem_post(philo->data->dead);
	return (0);
}

void	free_all(t_philo *philo)
{
	sem_close(philo->data->fork);
	sem_unlink("/philo_fork");
	sem_close(philo->data->print);
	sem_unlink("/philo_print");
	sem_close(philo->data->dead);
	sem_unlink("/philo_dead");
	sem_close(philo->data->sem_eaten);
	sem_unlink("/philo_eaten");
	free(philo->data);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	int			i;
	pthread_t	th;

	i = -1;
	if (check_args(argc, argv) != 0)
		return (1);
	philo = init_philos(argc, argv);
	if (argv[5])
		pthread_create(&th, NULL, &all_have_eat, philo);
	while (++i < philo->data->philo_num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			routine(&(philo[i]));
		usleep(100);
	}
	sem_wait(philo->data->dead);
	i = -1;
	while (++i < philo->data->philo_num)
		kill(philo[i].pid, SIGKILL);
	if (argv[5])
		pthread_join(th, NULL);
	free_all(philo);
	return (0);
}
