/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intiate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:41 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/16 11:09:38 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checkspaces(char **argv)
{
	int	i2;
	int	i;

	i2 = 0;
	i = 1;
	while (argv[i])
	{
		i2 = 0;
		while (argv[i][i2])
		{
			if (argv[i][i2++] != ' ')
				break ;
			else if (argv[i][i2] == 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}	
		}
		i++;
	}
}

static void	checkinvalid(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i <= argc - 1)
	{
		if (!argv[i][0])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	checkspaces(argv);
}

char	**joinn(int argc, char **argv)
{
	char	*r;
	char	**newargv;
	int		i;

	checkinvalid(argc, argv);
	r = argv[1];
	i = 1;
	while (++i < argc)
		r = ft_strjoin(r, argv[i], i);
	newargv = ft_split(r, ' ');
	if (argc > 2)
		free(r);
	return (newargv);
}

void	intiate(int *newargc, char **argv, t_list **stack)
{
	int	i;

	*newargc = 0;
	i = 0;
	while (argv[i++])
		*newargc = *newargc + 1;
	i = -1;
	while (++i < *newargc)
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i]), i));
	freearg(argv);
}
