/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:16:19 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/20 16:06:43 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int				i;

	i = 0;
	if (pthread_mutex_init(&data->print, NULL))
		return (print_error("Mutex not initialized."));
	if (pthread_mutex_init(&data->meals, NULL))
		return (print_error("Mutex not initialized."));
	if (pthread_mutex_init(&data->time, NULL))
		return (print_error("Mutex not initialized."));
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (print_error("Forks not initialized."));
	}
	return (0);
}

int	destroy_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->meals);
	return (0);
}
