/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:22:16 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 10:16:40 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*survival_check(void *received_t_data)
{
	t_data		*data;
	long long	time_since_meal;

	data = (t_data *)received_t_data;
	while (42)
	{
		usleep(50);
		if (!check_times_to_eat(data))
			break ;
		sem_wait(data->sem_lastmeal[data->id]);
		time_since_meal = get_timestamp(data) - data->last_meal;
		sem_post(data->sem_lastmeal[data->id]);
		if (time_since_meal >= data->time_to_die / 1000)
		{
			sem_wait(data->sem_didnt_survive);
			smart_print(data, "dies");
			sem_wait(data->sem_print);
			data->surviving = 0;
			exit (1);
			break ;
		}
	}
	return (NULL);
}

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
