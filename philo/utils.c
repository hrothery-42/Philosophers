/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:48:59 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 08:25:24 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_check(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&data->print);
	dead = data->is_dead;
	pthread_mutex_unlock(&data->print);
	return (dead);
}

void	death_print(t_philo *philo, char *s)
{
	philo->data->is_dead = 1;
	printf("%lld	%d %s\n", get_timestamp(philo), philo->id + 1, s);
}

void	safe_print(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->is_dead == 0)
		printf("%lld	%d %s\n", get_timestamp(philo), philo->id + 1, s);
	pthread_mutex_unlock(&philo->data->print);
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
