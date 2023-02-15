/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore50.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:35:16 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/15 09:05:39 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pushlargest(t_list **a_stack, t_list **b_stack)
{
	t_list	*temp;

	temp = *b_stack;
	while (temp)
	{
		if (temp->order == maxnum(*b_stack) && temp->pos == 0)
		{
			push_a(b_stack, a_stack);
			return (1);
		}
		else if (temp->order == maxnum(*b_stack) && temp->pos != 0)
		{
			if (temp->pos <= (ft_lstsize(*b_stack) / 2))
				rotatupper(temp->pos, b_stack, 'b');
			else if (temp->pos > (ft_lstsize(*b_stack) / 2))
				rotatlower(ft_lstsize(*b_stack) - temp->pos, b_stack, 'b');
			push_a(b_stack, a_stack);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

static int	pushchunks(t_list **a_stack, t_list **b_stack, int rangs, int rangd)
{
	t_list	*temp;

	temp = *a_stack;
	while (temp)
	{
		if (temp->order >= rangs && temp->order < rangd && temp->pos == 0)
		{
			push_b(a_stack, b_stack);
			return (1);
		}
		else if (temp->order >= rangs && temp->order < rangd && temp->pos != 0)
		{
			if (temp->pos <= (ft_lstsize(*a_stack) / 2))
				rotatupper(temp->pos, a_stack, 'a');
			else if (temp->pos > (ft_lstsize(*a_stack) / 2))
				rotatlower(ft_lstsize(*a_stack) - temp->pos, a_stack, 'a');
			push_b(a_stack, b_stack);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	sortmore50(t_list **a_stack, t_list **b_stack, int chunk, int size)
{
	int	rangs;
	int	rangd;
	int	check;

	if (chunk <= 100)
		chunk = 18;
	else
		chunk = 40;
	while (1)
	{
		rangs = size ;
		rangd = size + chunk;
		check = 1;
		while (check)
			check = pushchunks(a_stack, b_stack, rangs, rangd);
		size = size + chunk;
		if (ft_lstsize(*a_stack) == 0)
			break ;
	}
	check = 1;
	while (check)
		check = pushlargest(a_stack, b_stack);
}
