/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort23.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:32:09 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 08:32:31 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **s)
{
	if ((*s)->order > (*s)->next->order)
		swap_a(s);
}

void	sort3(t_list **s)
{
	if ((*s)->order > (*s)->next->order &&
			(*s)->next->order > (*s)->next->next->order)
	{
		swap_a(s);
		r_rotate_a(s);
	}
	else if ((*s)->order > (*s)->next->order && (*s)->next->order <
				(*s)->next->next->order && (*s)->next->next->order < (*s)->order)
		rotate_a(s);
	else if ((*s)->order < (*s)->next->order && (*s)->next->order >
			(*s)->next->next->order && (*s)->next->next->order > (*s)->order)
	{
		swap_a(s);
		rotate_a(s);
	}
	else if ((*s)->order > (*s)->next->order && (*s)->next->order <
				(*s)->next->next->order)
		swap_a(s);
	else if ((*s)->order < (*s)->next->order && (*s)->next->order >
				(*s)->next->next->order && (*s)->next->next->order < (*s)->order)
		r_rotate_a(s);
}
