/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:45:34 by jvasseur          #+#    #+#             */
/*   Updated: 2023/06/09 17:09:30 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	verif_unsigned_int(t_data *data, char **argv)
{
	int	i;

	i = 0;
	if (ft_atoi(argv[1]) == 0)
	{
		free(data);
		write(2, "number of philosopher <= 0 or error max / min int \n", 52);
		return (0);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			write(2, "Error unsigned int argment or abusive sign \n", 45);
			free(data);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	verif_arg_empty(t_data *data, char **argv)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	while (argv[i])
	{
		j = 0;
		cpt = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '\t' && argv[i][j] != 32)
				cpt++;
			j++;
		}
		if (cpt == 0)
		{
			write(2, "Error empty argment\n", 21);
			free(data);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	verif_int(t_data *data, char **argv)
{
	int	i;
	int	j;
	int	cpt;

	i = 1;
	while (argv[i])
	{
		j = 0;
		cpt = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57)
				&& (argv[i][j] != '+' && argv[i][j] != '-'))
				cpt++;
			j++;
		}
		if (cpt != 0)
		{
			write(2, "Error arg is not int or not only int\n", 21);
			free(data);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	verif_max_or_min_int(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((ft_atoi(argv[i]) == 0 && ft_atio(argv[i]) == 10)
			|| (ft_atoi(argv[i]) == -1 && ft_atio(argv[i]) == 10))
		{
			write(2, "One argment is > than MAX INT or < than MIN INT\n", 49);
			free(data);
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_all(t_data *data, char **argv)
{
	if (verif_arg_empty(data, argv) == 0)
		return (0);
	if (verif_int(data, argv) == 0)
		return (0);
	if (verif_unsigned_int(data, argv) == 0)
		return (0);
	if (verif_max_or_min_int(data, argv) == 0)
		return (0);
	return (1);
}
