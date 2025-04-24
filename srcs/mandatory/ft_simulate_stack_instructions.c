/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulate_stack_instructions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:22:09 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:04 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Simulate the rotation(r*) computed on the real stack
	5, 0, 1, 2, 3, 4 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_rotate(t_stack **stack, char stack_name)
{
	if (!(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
	if (ft_char_in_array(stack_name, "abr"))
		ft_printf("r%c\n", stack_name);
}

/* Simulate the reverse rotation(rr*) computed on the real stack
	1, 2, 3, 4, 5, 0 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_reverserotate(t_stack **stack, char stack_name)
{
	if (!(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
	if (ft_char_in_array(stack_name, "abr"))
		ft_printf("rr%c\n", stack_name);
}

/* Simulate the swap(s*) computed on the real stack
	1, 0, 2, 3 -> 0, 1, 2, 3
*/
void	ft_simulate_stack_swap(t_stack *stack, char stack_name)
{
	int	temp;

	if (!stack || stack->next == stack)
		return ;
	temp = stack->curr;
	stack->curr = stack->next->curr;
	stack->next->curr = temp;
	if (ft_char_in_array(stack_name, "abs"))
		ft_printf("s%c\n", stack_name);
}

/* Simulate the push(p*) computed on the real stack
	pb: a{ 3, 1, 0 } b{   }
	->  a{ 1, 0    } b{ 3 }
	| StackIn = a, StackOut = b, to = b |
*/
void	ft_simulate_stack_push(t_stack **stackIn, t_stack **stackOut, char to)
{
	t_stack	*temp;

	if (!(*stackIn))
		return ;
	temp = NULL;
	if ((*stackIn)->next != (*stackIn))
	{
		temp = (*stackIn)->next;
		temp->prev = (*stackIn)->prev;
		temp->prev->next = temp;
	}
	(*stackIn)->prev = *stackIn;
	(*stackIn)->next = *stackIn;
	if (*stackOut)
	{
		(*stackIn)->prev = (*stackOut)->prev;
		(*stackIn)->next = (*stackOut);
		(*stackOut)->prev->next = (*stackIn);
		(*stackOut)->prev = (*stackIn);
	}
	*stackOut = *stackIn;
	*stackIn = temp;
	ft_printf("p%c\n", to);
}
