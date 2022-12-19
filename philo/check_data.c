/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:44:35 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 08:23:24 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_for_non_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_meals(t_data *data)
{
	int	meal_count;

	pthread_mutex_lock(&data->meals);
	meal_count = data->total_meals;
	pthread_mutex_unlock(&data->meals);
	return (meal_count);
}

void	death_checker(t_data *data)
{
	int	i;

	i = 0;
	while (!death_check(data) && check_meals(data))
	{
		while (i < data->number_of_philosophers)
		{
			if (time_since_meal(&data->ph[i]) > data->time_to_die)
			{
				pthread_mutex_lock(&data->print);
				death_print(&data->ph[i], "dies");
				pthread_mutex_unlock(&data->print);
				break ;
			}
			i++;
		}
		i = 0;
	}
}
