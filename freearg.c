/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freearg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:13:39 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/16 14:17:35 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freearg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	freestack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
