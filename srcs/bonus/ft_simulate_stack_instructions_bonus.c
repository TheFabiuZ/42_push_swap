/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulate_stack_instructions_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:22:09 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/26 16:19:08 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* Simulate the rotation(r*) computed on the real stack
	5, 0, 1, 2, 3, 4 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_rotate(t_stack **stack)
{
	if (!(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

/* Simulate the reverse rotation(rr*) computed on the real stack
	1, 2, 3, 4, 5, 0 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_reverserotate(t_stack **stack)
{
	if (!(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

/* Simulate the swap(s*) computed on the real stack
	1, 0, 2, 3 -> 0, 1, 2, 3
*/
void	ft_simulate_stack_swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->next == stack)
		return ;
	temp = stack->curr;
	stack->curr = stack->next->curr;
	stack->next->curr = temp;
}

/* Simulate the push(p*) computed on the real stack
	pb: a{ 3, 1, 0 } b{   }
	->  a{ 1, 0    } b{ 3 }
	| StackIn = a, StackOut = b, to = b |
*/
void	ft_simulate_stack_push(t_stack **stackIn, t_stack **stackOut)
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
}
