/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applications_rarb_rrarrb.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:45:36 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:29 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*ft_apply_rarb_else part*/
void	ft_apply_rarb_else(t_stacks *stacks, int c)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	while ((*b)->curr != c && ft_find_place_a(*a, c) > 0)
		ft_simulate_stack(stacks, "rr");
	while ((*b)->curr != c)
		ft_simulate_stack(stacks, "rb");
	while (ft_find_place_a(*a, c) > 0)
		ft_simulate_stack(stacks, "ra");
	ft_simulate_stack(stacks, "pa");
}

/*
	This function rotates both stack_a and stack_b
	in the same direction as required amount.
*/
int	ft_apply_rarb(t_stacks *stacks, int c, char s)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	if (s == 'a')
	{
		while ((*a)->curr != c && ft_find_place_b(*b, c) > 0)
			ft_simulate_stack(stacks, "rr");
		while ((*a)->curr != c)
			ft_simulate_stack(stacks, "ra");
		while (ft_find_place_b(*b, c) > 0)
			ft_simulate_stack(stacks, "rb");
		ft_simulate_stack(stacks, "pb");
	}
	else
		ft_apply_rarb_else(stacks, c);
	return (-1);
}

/*ft_apply_rrarrb_else part*/
void	ft_apply_rrarrb_else(t_stacks *stacks, int c)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	while ((*b)->curr != c && ft_find_place_a(*a, c) > 0)
		ft_simulate_stack(stacks, "rrr");
	while ((*b)->curr != c)
		ft_simulate_stack(stacks, "rrb");
	while (ft_find_place_a(*a, c) > 0)
		ft_simulate_stack(stacks, "rra");
	ft_simulate_stack(stacks, "pa");
}

/*
	This function rotate both stack_a and stack_b in the
	reverse direction as required amount.
*/
int	ft_apply_rrarrb(t_stacks *stacks, int c, char s)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	if (s == 'a')
	{
		while ((*a)->curr != c && ft_find_place_b(*b, c) > 0)
			ft_simulate_stack(stacks, "rrr");
		while ((*a)->curr != c)
			ft_simulate_stack(stacks, "rra");
		while (ft_find_place_b(*b, c) > 0)
			ft_simulate_stack(stacks, "rrb");
		ft_simulate_stack(stacks, "pb");
	}
	else
		ft_apply_rrarrb_else(stacks, c);
	return (-1);
}
