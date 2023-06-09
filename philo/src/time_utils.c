/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:48:05 by jules             #+#    #+#             */
/*   Updated: 2023/06/09 17:01:50 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(int ms, t_data *data)
{
	int	current_time;
	int	time;

	time = get_time();
	current_time = get_time();
	if (ms == 0)
		return (0);
	while (current_time - time < ms)
	{
		pthread_mutex_lock(&data->verif_m);
		if (data->verif_dead == 1)
		{
			pthread_mutex_unlock(&data->verif_m);
			return (0);
		}	
		pthread_mutex_unlock(&data->verif_m);
		usleep(500);
		current_time = get_time();
	}
	return (1);
}
