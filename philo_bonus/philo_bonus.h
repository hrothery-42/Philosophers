/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:00:40 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 10:22:06 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int					id;
	long long			last_meal;
	pid_t				philosopher[200];
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_to_eat;
	long long			start_time;
	sem_t				*sem_forks;
	sem_t				*sem_print;
	sem_t				*sem_didnt_survive;
	sem_t				*sem_meals[200];
	sem_t				*sem_lastmeal[200];
	int					surviving;
}		t_data;

//initialize.c
int			init_data(t_data *data, int argc, char **argv);

//error.c
int			print_instructions(void);
int			print_error(char *s);

//create_processes.c
int			create_philosophers(int i, t_data *data);

//utils.c
int			check_times_to_eat(t_data *data);
void		smart_print(t_data *data, char *s);
int			ft_atoi(const char *nptr);

//check_data.c
int			check_args_for_non_int(int argc, char **argv);
void		*survival_check(void *received_t_data);

//timestamp.c
long long	get_timestamp(t_data *data);

//free.c
void		destroy_forks(t_data *data);

#endif