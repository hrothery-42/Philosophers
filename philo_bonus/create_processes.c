/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:40:02 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 10:25:30 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philosopher_eats(t_data *data)
{
	sem_wait(data->sem_forks);
	smart_print(data, "takes a fork");
	sem_wait(data->sem_forks);
	sem_wait(data->sem_lastmeal[data->id]);
	data->last_meal = get_timestamp(data);
	sem_post(data->sem_lastmeal[data->id]);
	smart_print(data, "takes a fork");
	smart_print(data, "is eating");
	usleep(data->time_to_eat);
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	sem_wait(data->sem_meals[data->id]);
	data->times_to_eat--;
	sem_post(data->sem_meals[data->id]);
}

void	child_process(int i, t_data *data)
{
	pthread_t			survival_status;

	data->id = i;
	if (pthread_create(&survival_status, NULL, survival_check, (void *)data))
		printf("Thread not created.");
	if (i % 2)
		usleep(15000);
	if (data->number_of_philosophers == 1)
		usleep(data->time_to_die);
	while (data->times_to_eat && data->surviving)
	{
		philosopher_eats(data);
		if (data->times_to_eat)
		{
			smart_print(data, "is sleeping");
			usleep(data->time_to_sleep);
			smart_print(data, "is thinking");
		}
	}
	if (pthread_join(survival_status, NULL))
		printf("Thread not joined\n");
	exit(0);
}

void	kill_child_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		kill(data->philosopher[i], SIGKILL);
		i++;
	}
}

int	create_philosophers(int i, t_data *data)
{
	int		status;

	data->philosopher[i] = fork();
	if (data->philosopher[i] < 0)
		print_error("fork call failed");
	if (data->philosopher[i] == 0)
		child_process(i, data);
	if (data->philosopher[i] > 0)
	{
		i++;
		if (i < data->number_of_philosophers)
			create_philosophers(i, data);
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			kill_child_processes(data);
			break ;
		}
		i++;
	}
	return (0);
}
