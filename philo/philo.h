/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:57:42 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/21 08:21:32 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

struct	s_data;

typedef struct s_philo
{
	pthread_t		philosopher;
	int				id;
	int				id_right;
	struct s_data	*data;
	long long		timestamp;
}		t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				is_dead;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				total_meals;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	time;
	pthread_mutex_t	print;
	pthread_mutex_t	meals;
	long long		start_time;
	t_philo			ph[200];
}		t_data;

//error.c
int			print_instructions(void);
int			print_error(char *s);

//mutex.c
int			init_forks(t_data *data);
int			destroy_forks(t_data *data);

//timestamp.c
//void		count_down_times_to_eat(t_philo *philo);
void		init_start_time(t_data *data);
long long	time_since_meal(t_philo *philo);
long long	get_timestamp(t_philo *philo);

//eat_cycle.c
void		*eat_cycle(void	*received_t_philo);

//check_data.c
int			check_meals(t_data *data);
int			check_args_for_non_int(int argc, char **argv);
void		death_checker(t_data *data);

//utils.c
int			death_check(t_data *data);
void		safe_print(t_philo *philo, char *s);
void		death_print(t_philo *philo, char *s);
int			ft_atoi(const char *nptr);

//hands.c
void		philo_is_left_handed(t_philo *philo);
void		philo_is_right_handed(t_philo *philo);

#endif