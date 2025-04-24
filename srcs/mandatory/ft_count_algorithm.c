/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:07:11 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 19:46:27 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Algorithm for more than one hundred numbers*/
void	ft_count_algorithm(t_stacks *stacks)
{
	ft_simulate_stack(stacks, "pb");
	ft_simulate_stack(stacks, "pb");
	while (stacks->a)
	{
		stacks->mov_b = ft_countmva(stacks->a, stacks->b, \
									ft_stacksize(stacks->a));
		stacks->mov_a = ft_countmvb(ft_stacksize(stacks->a));
		ft_best_order(stacks, ft_convertmv(stacks));
		free(stacks->mov_b);
		free(stacks->mov_a);
	}
	ft_order_stack(&stacks->b, TRUE, 'b');
	while (stacks->b)
		ft_simulate_stack(stacks, "pa");
}

/*Search the higher number than n*/
int	ft_find_higher(t_stack *stack, int n)
{
	int	high;
	int	len;

	len = ft_stacksize(stack);
	high = ft_max(stack);
	while (len-- > 0)
	{
		if (stack->curr > n && stack->curr < high)
			high = stack->curr;
		stack = stack->next;
	}
	return (high);
}
