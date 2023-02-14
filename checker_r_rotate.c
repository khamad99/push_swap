/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_r_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:44:37 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 14:49:15 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

static void	r_rotate(t_list **stack)
{
	int		i;
	int		size;
	t_list	*beforelast;
	t_list	*last;

	size = ft_lstsize(*stack);
	beforelast = *stack;
	i = 1;
	while (i++ < size-1)
		beforelast = beforelast->next;
	last = ft_lstlast(*stack);
	beforelast->next = 0;
	last->next = (*stack);
	(*stack) = last;
}

void	r_rotate_rrr(t_list **stack, t_list **stack2)
{
	r_rotate(stack);
	r_rotate(stack2);
	reposition(stack);
	reposition(stack2);
}

void	r_rotate_a(t_list **stack)
{
	r_rotate(stack);
	reposition(stack);
}

void	r_rotate_b(t_list **stack)
{
	r_rotate(stack);
	reposition(stack);
}
