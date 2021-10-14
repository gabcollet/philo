/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:00:01 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/05 18:32:41 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->philo_num = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->t_launch = get_time_in_ms();
	data->status = alive;
	sem_unlink("/philo_fork");
	sem_unlink("/philo_dead");
	sem_unlink("/philo_print");
	sem_unlink("/philo_eaten");
	data->sem_eaten = sem_open("/philo_eaten", O_CREAT, 0700, 0);
	data->fork = sem_open("/philo_fork", O_CREAT, 0700, data->philo_num);
	data->print = sem_open("/philo_print", O_CREAT, 0700, 1);
	data->dead = sem_open("/philo_dead", O_CREAT, 0700, 0);
	if (argc == 6)
		data->num_eat = ft_atoi(argv[5]);
	else
		data->num_eat = 0;
	return (data);
}

t_philo	*init_philos(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = 0;
	data = init_data(argc, argv);
	philo = malloc(sizeof(t_philo) * data->philo_num);
	while (i < data->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].t_last_meal = 0;
		philo[i].num_eaten = 0;
		i++;
	}
	return (philo);
}
