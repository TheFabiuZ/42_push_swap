/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:48:32 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:11 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Free single stack*/
void	free_stack(t_stack *stack)
{
	t_stack	*freeme;

	if (!stack)
		return ;
	stack->prev->next = NULL;
	while (stack->next)
	{
		freeme = stack;
		stack = stack->next;
		free(freeme);
	}
	free(stack);
}

/*Free stack_a and stack_b*/
void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
}

/*Free the strings in matrix*/
void	free_strs(char **strs)
{
	char	**start;

	start = strs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(start);
}
