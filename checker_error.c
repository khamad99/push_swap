/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:49:50 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/15 08:46:24 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

static int	issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	issdigit(char **argv)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (argv[i2])
	{
		i = 0;
		while (argv[i2][i])
		{
			while (argv[i2][i] && issign(argv[i2][i]))
				i++;
			if (!ft_isdigit(argv[i2][i++]))
				return (0);
		}
		i2++;
	}
	return (1);
}

static int	isnotdublicat(char **argv)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (argv[i])
	{
		i2 = i;
		while (argv[i2])
		{
			if (ft_atoi(argv[i2]) > INT_MAX || ft_atoi(argv[i2]) < INT_MIN)
				return (1);
			if ((i != i2) && (ft_atoi(argv[i]) == ft_atoi(argv[i2])))
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}

int	errorh(char **argv)
{
	if (!issdigit(argv))
	{
		freearg(argv);
		return (1);
	}
	if (isnotdublicat(argv))
	{
		freearg(argv);
		return (1);
	}
	return (0);
}

void	exit_function(t_list *a_stack, t_list *b_stack, int i)
{
	(void) a_stack;
	(void) b_stack;
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (i == 2)
	{
		freestack(a_stack);
		exit(1);
	}
	else if (i == 3)
	{
		freestack(a_stack);
		freestack(b_stack);
		return ;
	}
}
