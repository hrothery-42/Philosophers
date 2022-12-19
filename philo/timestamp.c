/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:18:04 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 08:25:13 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_start_time(t_data *data)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	data->start_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
}

long long	time_since_meal(t_philo *philo)
{
	long long	time_elapse;

	pthread_mutex_lock(&philo->data->time);
	time_elapse = get_timestamp(philo) - philo->timestamp;
	pthread_mutex_unlock(&philo->data->time);
	return (time_elapse);
}

long long	get_timestamp(t_philo *philo)
{
	struct timeval	t;
	long long		current_time;
	long long		timestamp;

	gettimeofday(&t, NULL);
	current_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	timestamp = current_time - philo->data->start_time;
	return (timestamp);
}
