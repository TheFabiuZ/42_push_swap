/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_initialization_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:59:16 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/05/07 20:27:06 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Initialise the t_stacks struct variable*/
void	ft_initialise_stacks(t_stacks *stacks, int length)
{
	stacks->length = length - 1;
	stacks->moves = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}

/*Recreate the stack (after allocated memory)*/
void	recreate_stack_a(char **stack, t_stack *a)
{
	t_stack	*curr_stack;
	int		i;

	curr_stack = a;
	i = 0;
	while (stack[i])
	{
		curr_stack->curr = ft_atoi(stack[i]);
		curr_stack = curr_stack->next;
		i++;
	}
}
