/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:13:25 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 08:31:18 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void	rotate(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*last;

	last = ft_lstlast((*stack));
	temp1 = (*stack)->next;
	temp2 = (*stack);
	(*stack)->next = 0;
	(*stack) = temp1;
	last->next = temp2;
}

void	rotate_rr(t_list **stack, t_list **stack2)
{
	rotate(stack);
	rotate(stack2);
	reposition(stack);
	reposition(stack2);
	ft_printf("rr\n");
}

void	rotate_a(t_list **stack)
{
	rotate(stack);
	reposition(stack);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack)
{
	rotate(stack);
	reposition(stack);
	ft_printf("rb\n");
}
