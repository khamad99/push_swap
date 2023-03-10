/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:33:46 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/15 08:55:44 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack, t_list **stack2)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_front(stack2, temp);
}

void	push_b(t_list **stack, t_list **stack2)
{
	if (!stack)
		return ;
	push(stack, stack2);
	reposition(stack);
	reposition(stack2);
	ft_printf("pb\n");
}

void	push_a(t_list **stack2, t_list **stack)
{
	if (!stack2)
		return ;
	push(stack2, stack);
	reposition(stack);
	reposition(stack2);
	ft_printf("pa\n");
}
