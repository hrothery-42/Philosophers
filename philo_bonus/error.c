/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:56:47 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/11 10:34:36 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_instructions(void)
{
	printf("Error!\nRun program with ./philo number_of_philosphers ");
	printf("time_to_die time_to_eat time_to_sleep [number_of_times_");
	printf("each_philosopher_must_eat]\n");
	return (1);
}

int	print_error(char *s)
{
	printf("Error! \n%s\n", s);
	return (1);
}
