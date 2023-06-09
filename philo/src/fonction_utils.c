/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:34:02 by jvasseur          #+#    #+#             */
/*   Updated: 2023/06/09 17:18:51 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	maxmin_int(long int nb, int sign)
{
	if (nb * sign > INT_MAX)
		return (-1);
	return (0);
}

int	maxmin_int_atio(long int nb, int sign)
{
	if (nb * sign > INT_MAX)
		return (10);
	return (10);
}

int	ft_atio(const char*str)
{
	int			i;
	int			sign;
	long int	nb;
	int			k;

	sign = 1;
	nb = 0;
	i = 0;
	k = maxmin_int_atio(nb, sign);
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (k);
		i++;
	}	
	return (nb * sign);
}

int	verif_unsigned(const char*str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		while (str[*i] == '-' || str[*i] == '+')
		{
			if (str[*i] == '-')
				return (-1);
			(*i)++;
		}
	}
	return (1);
}

int	ft_atoi(const char*str)
{
	int			i;
	int			sign;
	long int	nb;
	int			k;

	sign = 1;
	nb = 0;
	i = 0;
	k = maxmin_int(nb, sign);
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (verif_unsigned(str, &i) == -1)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (k);
		i++;
	}	
	return (nb * sign);
}
