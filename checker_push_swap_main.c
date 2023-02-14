/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:50:40 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 15:01:11 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ex_instractions(char *move, t_list **a_stack, t_list **b_stack)
{
	if (!ft_strncmp(move, "sa", 2))
		swap_a(a_stack);
	if (!ft_strncmp(move, "sb", 2))
		swap_b(b_stack);
	if (!ft_strncmp(move, "ss", 2))
		swap_ss(a_stack, b_stack);
	if (!ft_strncmp(move, "ra", 2))
		rotate_a(a_stack);
	if (!ft_strncmp(move, "rb", 2))
		rotate_b(b_stack);
	if(!ft_strncmp(move, "rr", 2))
		rotate_rr(a_stack, b_stack);
	if (!ft_strncmp(move, "rra", 3))
		r_rotate_a(a_stack);
	if (!ft_strncmp(move, "rrb", 3))
		r_rotate_b(b_stack);
	if (!ft_strncmp(move, "rrr", 3))
		r_rotate_rrr(a_stack, b_stack);
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*temp;
	int		newargc;
	char	*move;

	move = NULL;
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
	while (move)
	{
		move = get_next_line(1);
		ex_instractions(move, &a_stack, &b_stack);
	}
	if (issorted (a_stack) && !b_stack)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_function(a_stack, b_stack, 3);
	return (0);
}
