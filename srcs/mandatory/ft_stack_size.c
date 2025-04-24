/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:01:03 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:56:54 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Stack size*/
int	ft_stacksize(t_stack *stack)
{
	t_stack	*start;
	int		i;

	if (!stack)
		return (0);
	start = stack;
	i = 1;
	while (start->next != stack)
	{
		start = start->next;
		i++;
	}
	return (i);
}

/*Last element of the stack*/
t_stack	*ft_stacklast(t_stack *start)
{
	t_stack	*stack;

	if (!start)
		return (NULL);
	stack = start;
	while (stack->next != start)
		stack = stack->next;
	return (stack);
}

/*This function finds and returns the smallest number in the given stack*/
int	ft_min(t_stack *start)
{
	t_stack	*stack;
	int		i;

	i = start->curr;
	stack = start;
	while (stack->next != start)
	{
		if (stack->curr < i)
			i = stack->curr;
		stack = stack->next;
	}
	if (stack->curr < i)
		i = stack->curr;
	return (i);
}

/*This function finds and returns the biggest number in the given stack*/
int	ft_max(t_stack *start)
{
	t_stack	*stack;
	int		i;

	i = start->curr;
	stack = start;
	while (stack->next != start)
	{
		if (stack->curr > i)
			i = stack->curr;
		stack = stack->next;
	}
	if (stack->curr > i)
		i = stack->curr;
	return (i);
}
