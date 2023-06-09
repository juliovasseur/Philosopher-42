/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:48:14 by jvasseur          #+#    #+#             */
/*   Updated: 2023/06/09 17:02:15 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				number_philo;
	int				eat_cpt;
	int				fork;
	long int		last_time_eat;
	long int		last_time_sleep;
	pthread_t		thread_philo;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_rigth;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				argc;
	int				verif_dead;
	long int		time_start;
	long int		nb_philosopher;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	last_time_eat;
	pthread_mutex_t	eat_cpt;
	pthread_mutex_t	verif_m;
	t_philo			*philo;
}	t_data;

				/*fonction_utils.c*/

int		ft_atoi(const char*str);
int		ft_atio(const char*str);

				/*init.c*/

void	set_data(char **argv, t_data *data);

void	init_all_philo(t_data *data);

				/*parsing.c*/

int		verif_all(t_data *data, char **argv);

				/*philo.c*/

void	print(t_philo *philo, char *str);

				/*program_philo.c*/

void	*routine(void *s);

				/*time_utils.c*/

long	get_time(void);

int		ft_usleep(int ms, t_data *data);

				/*check_death.c*/

void	*check_death(void *s);

#endif
