/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:00:01 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/06 14:27:25 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_forks(t_data *data)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

void	update_list(t_data *data, int philo_id)
{
	int	i;

	i = 0;
	while (i < data->philo_num - 1)
	{
		data->list[i] = data->list[i + 1];
		i++;
	}
	data->list[i] = philo_id;
}

int	*init_list(t_data *data)
{
	int	*list;
	int	i;
	int	philo_id;

	i = 0;
	philo_id = 1;
	list = malloc(sizeof(int) * data->philo_num);
	while (philo_id <= data->philo_num)
	{
		list[i] = philo_id;
		i++;
		philo_id += 2;
	}
	philo_id = 2;
	while (philo_id <= data->philo_num)
	{
		list[i] = philo_id;
		i++;
		philo_id += 2;
	}
	return (list);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->philo_num = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->t_launch = get_time_in_ms();
	data->fork = init_forks(data);
	data->status = alive;
	data->list = init_list(data);
	pthread_mutex_init(&data->print, NULL);
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
