/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:48:24 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 08:31:54 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	destroy_child_semaphores(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		sem_close(data->sem_meals[i]);
		sem_close(data->sem_lastmeal[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		sem_unlink("/sem_meals[i]");
		sem_unlink("/sem_lastmeal[i]");
		i++;
	}
}

void	destroy_forks(t_data *data)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
	sem_close(data->sem_didnt_survive);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	sem_unlink("sem_didnt_survive");
	destroy_child_semaphores(data);
}
