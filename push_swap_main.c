/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:50:40 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 11:44:16 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*temp;
	int		newargc;

	a_stack = NULL;
	b_stack = NULL;
	temp = NULL;
	if (argc <= 1)
		return (0);
	argv = joinn(argc, argv);
	if (errorh(argv))
	 	exit_function(a_stack, b_stack, 1);
	intiate(&newargc, argv, &a_stack);
	if (issorted(a_stack))
		exit_function(a_stack, b_stack, 2);
	order(a_stack, temp, ft_lstsize(a_stack), 0);
	sort(&a_stack, &b_stack, newargc);
	exit_function(a_stack, b_stack, 3);
	return (0);
}
