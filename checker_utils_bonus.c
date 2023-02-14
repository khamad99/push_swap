/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:15:08 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 22:32:18 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
