/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:27:03 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/19 09:12:20 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_timestamp(t_data *data)
{
	struct timeval	t;
	long long		current_time;
	long long		timestamp;

	gettimeofday(&t, NULL);
	current_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	timestamp = current_time - data->start_time;
	return (timestamp);
}
