/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:46:33 by jvasseur          #+#    #+#             */
/*   Updated: 2023/06/09 16:51:42 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_all_final(t_data *data)
{
	pthread_mutex_destroy(&data->eat_cpt);
	pthread_mutex_destroy(&data->last_time_eat);
	pthread_mutex_destroy(&data->verif_m);
	pthread_mutex_destroy(&data->print);
	free(data->philo);
	free(data);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->verif_m);
	if (philo->data->verif_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->verif_m);
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	pthread_mutex_unlock(&philo->data->verif_m);
	time = get_time() - philo->data->time_start;
	if (time >= 0)
		printf("%ld %d %s", get_time() - philo->data->time_start,
			philo->number_philo, str);
	pthread_mutex_unlock(&philo->data->print);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 6 && argc != 5)
		return (0);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
			return (0);
	}
	if (ft_atoi(argv[1]) > 200)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error malloc");
		return (0);
	}
	data->argc = argc;
	if (verif_all(data, argv) == 0)
		return (0);
	set_data(argv, data);
	init_all_philo(data);
	free_all_final(data);
	return (0);
}
