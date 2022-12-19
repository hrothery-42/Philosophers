/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:59:05 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 09:59:56 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_more_semaphores(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		sem_unlink("/sem_meals[i]");
		sem_unlink("/sem_lastmeal[i]");
		data->sem_meals[i] = sem_open("/sem_meals[i]", O_CREAT, 0644, 1);
		data->sem_lastmeal[i] = sem_open("/sem_lastmeal[i]", O_CREAT, 0644, 1);
		if (data->sem_meals[i] == SEM_FAILED || data->sem_lastmeal[i] \
		== SEM_FAILED)
			return (print_error("sem open failed"));
		i++;
	}
	return (0);
}

int	init_semaphores(t_data *data)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	sem_unlink("/sem_didnt_survive");
	data->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, \
	data->number_of_philosophers);
	if (data->sem_forks == SEM_FAILED)
		return (print_error("sem open failed"));
	data->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	if (data->sem_print == SEM_FAILED)
		return (print_error("sem open failed"));
	data->sem_didnt_survive = sem_open("/sem_didnt_survive", O_CREAT, 0644, 1);
	if (data->sem_didnt_survive == SEM_FAILED)
		return (print_error("sem open failed"));
	return (init_more_semaphores(data));
}

void	init_more_data(t_data *data, int argc, char **argv)
{
	struct timeval	t;

	if (argc == 6)
		data->times_to_eat = ft_atoi(argv[5]);
	else
		data->times_to_eat = -1;
	data->surviving = 1;
	data->id = 0;
	data->last_meal = 0;
	gettimeofday(&t, NULL);
	data->start_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (check_args_for_non_int(argc, argv) == 1)
		return (print_error("Contains non-integer argument(s)."));
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers > 200)
		return (print_error("Use no more than 200 philosophers."));
	if (data->number_of_philosophers == 0)
		return (print_error("Enter more than 1 philosopher."));
	data->time_to_die = ft_atoi(argv[2]) * 1000;
	if (data->time_to_die < 60000)
		return (print_error("Time_to_die must be at least 60 msec."));
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	if (data->time_to_eat < 60000)
		return (print_error("Time_to_eat must be at least 60 msec."));
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (data->time_to_sleep < 60000)
		return (print_error("Time_to_sleep must be at least 60 msec."));
	init_more_data(data, argc, argv);
	return (init_semaphores(data));
}
