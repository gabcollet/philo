/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:41:21 by gcollet           #+#    #+#             */
/*   Updated: 2021/10/12 14:42:19 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		nptr++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		nptr++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}

long long	get_time_in_ms(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_in_ms);
}

void	smart_sleep(long long time, t_philo *philo)
{
	long long	time_in_ms;

	time_in_ms = get_time_in_ms();
	check_status(philo);
	while (philo->data->status == alive)
	{
		if (get_time_in_ms() - time_in_ms > philo->data->t_die - 1)
			print_dead(philo);
		if (get_time_in_ms() - time_in_ms >= time)
			break ;
		usleep(50);
	}
}

void	print_status(t_philo *philo, char *str)
{
	long long	time_in_ms;

	sem_wait(philo->data->print);
	time_in_ms = get_time_in_ms() - philo->data->t_launch;
	if (philo->data->status == alive)
		printf("%lld %d %s\n", time_in_ms, philo->id, str);
	sem_post(philo->data->print);
}

void	print_dead(t_philo *philo)
{
	long long	time_in_ms;

	sem_wait(philo->data->print);
	time_in_ms = get_time_in_ms() - philo->data->t_launch;
	printf("%lld %d died\n", time_in_ms, philo->id);
	sem_post(philo->data->dead);
}
