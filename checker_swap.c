/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:19 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 14:50:05 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	temp2 = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->next->next = temp2;

}

void	swap_ss(t_list **stack, t_list **stack2)
{
	if (ft_lstsize(*stack) < 2)
		return;
	if (ft_lstsize(*stack2) < 2)
		return;
	swap(stack);
	swap(stack2);
	reposition(stack);
	reposition(stack2);
}

void	swap_a(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return;
	swap(stack);
	reposition(stack);
}

void	swap_b(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return;
	swap(stack);
	reposition(stack);
}