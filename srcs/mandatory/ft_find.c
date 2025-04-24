/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:05:23 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/05/07 19:01:21 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Check the node content at n position in stack*/
int	ft_checknode(t_stack *stack, int n)
{
	while (n-- > 0)
		stack = stack->next;
	return (stack->curr);
}

/*
	Check the index of stack
	Negative: The number is closer to the end of the stack
*/
int	ft_checkindex(t_stack *stack, int number, int length)
{
	t_stack	*start;
	int		index;

	if (length <= 1)
		return (0);
	start = stack;
	index = -1;
	while (++index < length / 2)
	{
		if (stack->curr == number)
			return (index);
		stack = stack->next;
	}
	index = 0;
	stack = start;
	while (length-- > 0)
	{
		if (stack->curr == number)
			return (index);
		index--;
		stack = stack->prev;
	}
	return (index);
}

/*This function checks the index of a number in the stack.*/
int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->curr != nbr)
	{
		i++;
		a = a->next;
	}
	a->id = 0;
	return (i);
}

/*
	This function finds the correct place of the number in stack_b.
	In other words, it check what index number nbr_push will get 
	after it is being pushed to the stack_b.
*/
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->curr && nbr_push < ft_stacklast(stack_b)->curr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->curr < nbr_push || tmp->curr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/*
	This function finds the correct place of the number in stack_a.
	In other words, it check what index number nbr_push will get 
	after it is being pushed to the stack_a.
*/
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->curr && nbr_push > ft_stacklast(stack_a)->curr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->curr > nbr_push || tmp->curr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
