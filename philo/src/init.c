/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:48:59 by jules             #+#    #+#             */
/*   Updated: 2023/06/09 16:37:31 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_data(char **argv, t_data *data)
{
	data->nb_philosopher = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	data->verif_dead = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->verif_m, NULL);
	pthread_mutex_init(&data->last_time_eat, NULL);
	pthread_mutex_init(&data->eat_cpt, NULL);
}

void	malloc_and_more(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nb_philosopher);
	if (!data->philo)
	{
		perror("error malloc");
		free(data);
		exit(1);
	}
	data->time_start = get_time();
}

void	p_thread_help(t_data *data)
{
	int			i;
	pthread_t	th_philo;

	i = 0;
	while (data->nb_philosopher > i)
	{
		pthread_create(&data->philo[i].thread_philo,
			NULL, &routine, &data->philo[i]);
		i++;
	}
	pthread_create(&th_philo, NULL, &check_death, data);
	i = 0;
	while (data->nb_philosopher > i)
	{
		pthread_join(data->philo[i].thread_philo, NULL);
		i++;
	}
	pthread_join(th_philo, NULL);
}

void	init_all_philo(t_data *data)
{
	int			i;

	malloc_and_more(data);
	i = 0;
	while (i < data->nb_philosopher)
	{
		data->philo[i].number_philo = i + 1;
		data->philo[i].data = data;
		data->philo[i].eat_cpt = 0;
		data->philo[i].last_time_eat = 0;
		pthread_mutex_init(&(data->philo[i].fork_left), NULL);
		if (i == data->nb_philosopher - 1)
			data->philo[i].fork_rigth = &data->philo[0].fork_left;
		else
			data->philo[i].fork_rigth = &data->philo[i + 1].fork_left;
		i++;
	}
	p_thread_help(data);
}
