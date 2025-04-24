/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:23:17 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:09 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// [TEST]
// Use for print in terminal a single stack in reverse
void	ft_print_stack_reverse(t_stack *stack)
{
	t_stack	*printing;

	if (!stack)
		return ;
	printing = stack->prev;
	while (printing != stack)
	{
		ft_printf("|\t%d\n", printing->curr);
		printing = printing->prev;
	}
	ft_printf("|\t%d\n", printing->curr);
}

// [TEST]
// Use for print in terminal a single stack
void	ft_print_stack(t_stack *stack)
{
	t_stack	*printing;

	if (!stack)
		return ;
	printing = stack;
	while (printing->next != stack)
	{
		ft_printf("|\t%d\n", printing->curr);
		printing = printing->next;
	}
	ft_printf("|\t%d\n", printing->curr);
}

// [TEST]
// Use for print in terminal the stacks | 1 = reverse
void	ft_print_stacks(t_stacks *stacks, t_bool rev_rule)
{
	if (rev_rule)
		ft_printf("\nREVERSED\n");
	ft_printf("\n----------\n|STACK a:\n");
	if (!rev_rule)
		ft_print_stack(stacks->a);
	else
		ft_print_stack_reverse(stacks->a);
	ft_printf("|---------\n|STACK b:\n");
	if (!rev_rule)
		ft_print_stack(stacks->b);
	else
		ft_print_stack_reverse(stacks->b);
	ft_printf("----------\n\n");
}
