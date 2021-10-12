/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:32:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/06 11:32:08 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taking_fork(t_philo *philo)
{
	sem_wait(philo->data->fork);
	print_status(philo, "has taken a fork");
	sem_wait(philo->data->fork);
	print_status(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	print_status(philo, "is eating");
	philo->t_last_meal = get_time_in_ms();
	philo->num_eaten++;
	sem_post(philo->data->sem_eaten);
	smart_sleep(philo->data->t_eat, philo);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}

void	*is_dead(void *void_philo)
{
	t_philo	*philo;

	philo = void_philo;
	while (1)
		check_status(philo);
}

void	*routine(void *void_philo)
{
	t_philo		*philo;
	pthread_t	th;

	philo = void_philo;
	pthread_create(&th, NULL, &is_dead, philo);
	pthread_detach(th);
	while (philo->data->status == alive)
	{
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
	exit (EXIT_SUCCESS);
}
