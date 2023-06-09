/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:24:57 by jvasseur          #+#    #+#             */
/*   Updated: 2023/06/09 16:41:30 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	help_booleen_death(t_data *data, int d)
{
	if (data->nb_philosopher == 1)
		return (0);
	if (data->argc == 6)
	{
		pthread_mutex_lock(&data->eat_cpt);
		if (data->philo[d].eat_cpt
			== data->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_unlock(&data->eat_cpt);
			return (0);
		}
		pthread_mutex_unlock(&data->eat_cpt);
	}
	return (1);
}

int	booleen_death(t_data *data, int d)
{
	int	i;
	int	tmp;

	i = get_time();
	pthread_mutex_lock(&data->last_time_eat);
	tmp = data->philo[d].last_time_eat;
	pthread_mutex_unlock(&data->last_time_eat);
	if (help_booleen_death(data, d) == 0)
		return (0);
	if (i - tmp >= data->time_to_die)
	{
		print(&data->philo[d], "died\n");
		pthread_mutex_lock(&data->verif_m);
		data->verif_dead = 1;
		pthread_mutex_unlock(&data->verif_m);
		return (0);
	}
	return (1);
}

void	*check_death(void *s)
{
	int		d;
	t_data	*data;

	data = s;
	d = 0;
	while (1)
	{
		if (booleen_death(data, d) == 0)
		{
			return (NULL);
		}
		if (d < data->nb_philosopher - 1)
			d++;
		else
			d = 0;
	}
}
