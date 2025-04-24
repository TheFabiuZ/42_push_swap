/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:13:39 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 19:48:45 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Check the content at n position*/
int	ft_check_content_pos(t_stack *stack, int n)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = stack->prev;
	while (stack != temp)
	{
		if (stack->curr == n)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

/*
	Order stack s:
	rev = TRUE: Order stack in REVERSE order
*/
void	ft_order_stack(t_stack **stack, t_bool reverse, char name)
{
	int	length;

	length = ft_stacksize(*stack);
	if (!reverse)
	{
		if (ft_checkindex(*stack, ft_min(*stack), length) < length / 2)
		{
			while ((*stack)->curr > (*stack)->prev->curr)
				ft_simulate_stack_rotate(stack, name);
		}
		else
			while ((*stack)->curr > (*stack)->prev->curr)
				ft_simulate_stack_reverserotate(stack, name);
	}
	if (reverse)
	{
		if (ft_check_content_pos(*stack, ft_min(*stack)) < length / 2)
		{
			while ((*stack)->curr < (*stack)->prev->curr)
				ft_simulate_stack_rotate(stack, name);
		}
		else
			while ((*stack)->curr < (*stack)->prev->curr)
				ft_simulate_stack_reverserotate(stack, name);
	}
}
