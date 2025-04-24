/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applications_rrarb_rarrb.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:40:53 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:26 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function rotate the stack_a in reverse direction,
	the stack_b in oppsite direction of stack_a as required amount.
*/
int	ft_apply_rrarb(t_stacks *stacks, int c, char s)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	if (s == 'a')
	{
		while ((*a)->curr != c)
			ft_simulate_stack(stacks, "rra");
		while (ft_find_place_b(*b, c) > 0)
			ft_simulate_stack(stacks, "rb");
		ft_simulate_stack(stacks, "pb");
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_simulate_stack(stacks, "rra");
		while ((*b)->curr != c)
			ft_simulate_stack(stacks, "rb");
		ft_simulate_stack(stacks, "pa");
	}
	return (-1);
}

/*
	This function rotate the stack_b in reverse direction,
	the stack_a in oppsite direction of stack_a as required amount.
*/
int	ft_apply_rarrb(t_stacks *stacks, int c, char s)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	if (s == 'a')
	{
		while ((*a)->curr != c)
			ft_simulate_stack(stacks, "ra");
		while (ft_find_place_b(*b, c) > 0)
			ft_simulate_stack(stacks, "rrb");
		ft_simulate_stack(stacks, "pb");
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_simulate_stack(stacks, "ra");
		while ((*b)->curr != c)
			ft_simulate_stack(stacks, "rrb");
		ft_simulate_stack(stacks, "pa");
	}
	return (-1);
}
