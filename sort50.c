/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort50.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:33:26 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/15 09:03:59 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushsmallest(t_list **a_stack, t_list **b_stack)
{
	t_list	*temp;

	temp = *a_stack;
	while (temp)
	{
		if (temp->order == minnum(*a_stack) && temp->pos == 0)
		{
			push_b(a_stack, b_stack);
			return ;
		}
		else if (temp->order == minnum(*a_stack) && temp->pos != 0)
		{
			if (temp->pos <= (ft_lstsize(*a_stack) / 2))
				rotatupper(temp->pos, a_stack, 'a');
			else if (temp->pos > (ft_lstsize(*a_stack) / 2))
				rotatlower(ft_lstsize(*a_stack) - temp->pos, a_stack, 'a');
			push_b(a_stack, b_stack);
			return ;
		}
		temp = temp->next;
	}
	return ;
}

void	sort50(t_list **a_stack, t_list **b_stack)
{
	int	size;
	int	size2;

	size = ft_lstsize(*a_stack);
	size2 = 0;
	while ((size - 3) > 0)
	{
		pushsmallest(a_stack, b_stack);
		size2++;
		size--;
	}
	if (!issorted (*a_stack))
		sort3(a_stack);
	while (size2-- > 0)
		push_a(b_stack, a_stack);
}
