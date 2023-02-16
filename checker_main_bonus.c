/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:50:40 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/16 11:21:33 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ex_instractions(char *move, t_list **a_stack, t_list **b_stack)
{
	if (ft_strncmp("rra", move, 3) == 0)
		r_rotate_a(a_stack);
	else if (ft_strncmp("rrb", move, 3) == 0)
		r_rotate_b(b_stack);
	else if (ft_strncmp("rrr", move, 3) == 0)
		r_rotate_rrr(a_stack, b_stack);
	else if (ft_strncmp("pa", move, 2) == 0)
		push_a(b_stack, a_stack);
	else if (ft_strncmp("pb", move, 2) == 0)
		push_b(a_stack, b_stack);
	else if (ft_strncmp("sa", move, 2) == 0)
		swap_a(a_stack);
	else if (ft_strncmp("sb", move, 2) == 0)
		swap_b(b_stack);
	else if (ft_strncmp("ss", move, 2) == 0)
		swap_ss(a_stack, b_stack);
	else if (ft_strncmp("ra", move, 2) == 0)
		rotate_a(a_stack);
	else if (ft_strncmp("rb", move, 2) == 0)
		rotate_b(b_stack);
	else if (ft_strncmp("rr", move, 2) == 0)
		rotate_rr(a_stack, b_stack);
}

static void	readfromfd(char *move, t_list **a_stack, t_list **b_stack)
{
	while (move)
	{
		if (move != 0)
		{
			ex_instractions(move, a_stack, b_stack);
			free(move);
		}
		move = get_next_line(0);
	}
}

static void	checksorted(t_list **a_stack)
{
	if (issorted(*a_stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		newargc;
	char	*move;

	move = 0;
	if (argc > 1)
	{
		argv = joinn(argc, argv);
		move = get_next_line(0);
	}
	else if (argc <= 1)
		return (0);
	a_stack = NULL;
	b_stack = NULL;
	if (errorh(argv))
		exit_function(a_stack, b_stack, 1);
	intiate(&newargc, argv, &a_stack);
	if (issorted(a_stack))
		exit_function(a_stack, b_stack, 2);
	readfromfd(move, &a_stack, &b_stack);
	checksorted(&a_stack);
	exit_function(a_stack, b_stack, 3);
	return (0);
}
