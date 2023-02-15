/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:50:59 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/15 09:04:55 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotatupper(int i, t_list **stack, char ab)
{
	if (ab == 'a')
	{
		while (i-- > 0)
			rotate_a(stack);
	}
	if (ab == 'b')
	{
		while (i-- > 0)
			rotate_b(stack);
	}
	return ;
}

void	rotatlower(int i, t_list **stack, char ab)
{
	if (ab == 'a')
	{
		while (i-- > 0)
			r_rotate_a(stack);
	}
	if (ab == 'b')
	{
		while (i-- > 0)
			r_rotate_b(stack);
	}
	return ;
}
