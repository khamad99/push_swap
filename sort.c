/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:55:01 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 08:49:04 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a_stack, t_list **b_stack, int num)
{
	(void)b_stack;
	if (num == 2)
		sort2(a_stack);
	if (num == 3)
		sort3(a_stack);
	if (num > 3 && num <= 50)
		sort50(a_stack, b_stack);
	if (num > 50)
		sortmore50(a_stack, b_stack, num, 0);
}
