/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:50:49 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/14 10:00:21 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

int		errorh(char **argv);
void	exit_function(t_list *a_stack, t_list *b_stack, int i);
int		issorted(t_list *stak);
void	intiate(int *newargc, char **argv, t_list **a_stack);
void	swap_ss(t_list **stack, t_list **stack2);
void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	r_rotate_rrr(t_list **stack, t_list **stack2);
void	r_rotate_a(t_list **stack);
void	r_rotate_b(t_list **stack);
void	rotate_rr(t_list **stack, t_list **stack2);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	push_b(t_list **stack, t_list **stack2);
void	push_a(t_list **stack2, t_list **stack);
int		maxnum(t_list *stak);
int		minnum(t_list *stak);
void	order(t_list *stak, t_list *temp, int size, int index);
void	moves(t_list **stack);
void	reposition(t_list **stack);
void	sort(t_list **a_stack, t_list **b_stack, int num);
char	**joinn(int argc, char **argv);
void	sort2(t_list **s);
void	sort3(t_list **s);
void	sort50(t_list **a_stack, t_list **b_stack);
void	sortmore50(t_list **a_stack, t_list **b_stack, int chunk, int size);
void	freearg(char **argv);
void	freestack(t_list *stack);
void	rotatupper(int i, t_list **stack, char ab);
void	rotatlower(int i, t_list **stack, char ab);



#endif