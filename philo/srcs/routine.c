/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:32:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/05 17:32:58 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print_status(philo, "has taken a fork");
	if (philo->id == philo->data->philo_num)
		pthread_mutex_lock(&philo->data->fork[0]);
	else
		pthread_mutex_lock(&philo->data->fork[philo->id]);
	print_status(philo, "has taken a fork");
	update_list(philo->data, philo->id);
}

void	eating(t_philo *philo)
{
	print_status(philo, "is eating");
	philo->t_last_meal = get_time_in_ms();
	philo->num_eaten++;
	smart_sleep(philo->data->t_eat, philo);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	if (philo->id == philo->data->philo_num)
		pthread_mutex_unlock(&philo->data->fork[0]);
	else
		pthread_mutex_unlock(&philo->data->fork[philo->id]);
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = void_philo;
	while (philo->data->status == alive)
	{
		check_status(philo);
		if (philo->id != philo->data->list[0])
			continue ;
		if (philo->data->philo_num != 1)
		{
			taking_fork(philo);
			eating(philo);
			if (philo->data->num_eat
				&& philo->num_eaten == philo->data->num_eat)
				break ;
			print_status(philo, "is sleeping");
			smart_sleep(philo->data->t_sleep, philo);
			print_status(philo, "is thinking");
		}
		check_status(philo);
	}
	return (0);
}
