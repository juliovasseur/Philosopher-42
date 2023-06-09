/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:50:36 by jules             #+#    #+#             */
/*   Updated: 2023/06/09 16:40:50 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	fork_philo(t_philo *philo)
{
	if (philo->data->nb_philosopher == 1)
	{
		pthread_mutex_lock(&philo->fork_left);
		print(philo, "has taken a fork\n");
		pthread_mutex_unlock(&philo->fork_left);
		ft_usleep(philo->data->time_to_die, philo->data);
		print(philo, "died\n");
		return (0);
	}
	pthread_mutex_lock(&philo->fork_left);
	print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->fork_rigth);
	print(philo, "has taken a fork\n");
	return (1);
}

int	eat_philo(t_philo *philo)
{
	print(philo, "is eating\n");
	pthread_mutex_lock(&philo->data->eat_cpt);
	philo->eat_cpt++;
	pthread_mutex_unlock(&philo->data->eat_cpt);
	pthread_mutex_lock(&philo->data->last_time_eat);
	philo->last_time_eat = get_time();
	pthread_mutex_unlock(&philo->data->last_time_eat);
	if (ft_usleep(philo->data->time_to_eat, philo->data) == 0)
	{
		pthread_mutex_unlock(&philo->fork_left);
		pthread_mutex_unlock(philo->fork_rigth);
		return (0);
	}
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork_rigth);
	print(philo, "is sleeping\n");
	if (ft_usleep(philo->data->time_to_sleep, philo->data) == 0)
		return (0);
	print(philo, "is thinking\n");
	return (1);
}

void	*routine(void *s)
{
	t_philo	*philo;

	philo = s;
	if (philo->number_philo % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (fork_philo(philo) == 0)
			return (NULL);
		if (eat_philo(philo) == 0)
			return (NULL);
		if (philo->data->argc == 6)
		{
			if (philo->eat_cpt
				== philo->data->number_of_times_each_philosopher_must_eat)
				return (NULL);
		}
	}
	return (NULL);
}
