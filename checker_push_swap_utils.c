/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:15:08 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 14:19:30 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int	issorted(t_list *stak)
{
	t_list	*temp;
	
	temp = stak;
	while (temp->next)
	{
		if(temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	maxnum(t_list *stak)
{
	t_list	*temp;
	int		max;
	
	max = INT_MIN;
	temp = stak;
	while (temp)
	{
		if (temp->next == NULL && temp->order > max)
			max = temp->order;
		else if (temp->next != NULL && temp->order > temp->next->order && temp->order > max)
			max = temp->order;
		temp = temp->next;
	}
	return (max);
}

int	minnum(t_list *stak)
{
	t_list	*temp;
	int		min;

	min = INT_MAX;
	temp = stak;
	while (temp)
	{
		if (temp->next == NULL && temp->order < min)
			min = temp->order;
		else if (temp->next != NULL && temp->order < temp->next->order && temp->order < min)
			min = temp->order;
		temp = temp->next;
	}
	return (min);
}

void	order(t_list *stak, t_list *temp, int size, int index)
{
	t_list	*high;

	while (--size > 0)
	{
		temp = stak;
		index = INT_MIN;
		high = NULL;
		while (temp)
		{
			if (temp->num == INT_MIN && temp->order == 0)
				temp->order = 1;
			if (temp->num > index && temp->order == 0)
			{
				index = temp->num;
				high = temp;
				temp = stak;
			}
			else
				temp = temp->next;
		}
		if (high)
			high->order = size;
	}
}

void	reposition(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		i++;
		temp = temp->next;
	}
}
