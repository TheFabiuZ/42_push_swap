/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_allocation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:03:30 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:56:56 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Create a node and fill the prev*/
t_stack	*ft_create_node(t_stack *p_node, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->prev = p_node;
	node->next = 0;
	node->curr = 0;
	node->id = n;
	return (node);
}

/*Allocate memory to stack*/
void	allocate_memory_to_stack(t_stack **stack, int length)
{
	t_stack	*curr_stack;
	t_stack	*first_stack;
	int		i;

	*stack = ft_create_node(NULL, 0);
	first_stack = *stack;
	curr_stack = first_stack;
	i = 1;
	while (i < length)
	{
		curr_stack->next = ft_create_node(curr_stack, i++);
		curr_stack = curr_stack->next;
	}
	first_stack->prev = curr_stack;
	curr_stack->next = first_stack;
}
