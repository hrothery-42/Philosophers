/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:48:59 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/19 12:00:35 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_times_to_eat(t_data *data)
{
	int	times;

	sem_wait(data->sem_meals[data->id]);
	times = data->times_to_eat;
	sem_post(data->sem_meals[data->id]);
	return (times);
}

void	smart_print(t_data *data, char *s)
{
	sem_wait(data->sem_print);
	printf("%lld %d %s\n", get_timestamp(data), data->id + 1, s);
	sem_post(data->sem_print);
}

void	smart_time(t_data *data, int time)
{
	struct timeval	t;
	long long		start_time;
	long long		current_time;

	gettimeofday(&t, NULL);
	start_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	while (1)
	{
		usleep(50);
		if (!data->surviving)
		{
			printf("exiting process\n");
			exit (1);
		}
		gettimeofday(&t, NULL);
		current_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
		if ((current_time - start_time) >= (time / 1000))
			return ;
	}
}

static int	ft_putn(char *p)
{
	int	i;
	int	nbr;

	i = 0;
	if (p[i] >= '0' && p[i] <= '9')
	{
		nbr = (p[i] - '0');
		i++;
	}
	else
		return (0);
	while (p[i] <= '9' && p[i] >= '0')
	{
		nbr = (nbr * 10) + (p[i] - '0');
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	neg_value;

	i = 0;
	n = 0;
	neg_value = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg_value = -1;
		i++;
	}
	n = ft_putn((char *)(nptr + i));
	return (n * neg_value);
}
