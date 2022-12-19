/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hands.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:23:01 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/20 09:44:49 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_left_handed(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	safe_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->id_right]);
	safe_print(philo, "has taken a fork");
}

void	philo_is_right_handed(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id_right]);
	safe_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	safe_print(philo, "has taken a fork");
}
