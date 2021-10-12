/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:34:41 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/12 10:01:17 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	create_threads(t_philo *philo)
{
	int			i;
	pthread_t	*th;

	i = -1;
	th = malloc(sizeof(pthread_t) * (philo->data->philo_num));
	while (++i < philo->data->philo_num)
		pthread_create(&th[i], NULL, routine, &philo[i]);
	i = 0;
	while (i < philo->data->philo_num)
		pthread_join(th[i++], NULL);
	free(th);
	free(philo->data->fork);
	free(philo->data->list);
	free(philo->data);
	free(philo);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc > 4 && argc <= 6)
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

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_args(argc, argv) != 0)
		return (1);
	philo = init_philos(argc, argv);
	create_threads(philo);
}
