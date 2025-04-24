/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_updater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:48:39 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:56:51 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Sort until in stack_a remain only three numbers*/
void	ft_sort_till_three(t_stacks *stacks)
{
	t_stack	*temp;
	int		i;

	while (ft_stacksize(stacks->a) > 3 && !ft_issorted(stacks->a))
	{
		temp = stacks->a;
		i = ft_rotate_type_ab(stacks->a, stacks->b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(stacks->a, stacks->b, temp->curr))
				i = ft_apply_rarb(stacks, temp->curr, 'a');
			else if (i == ft_case_rrarrb(stacks->a, stacks->b, temp->curr))
				i = ft_apply_rrarrb(stacks, temp->curr, 'a');
			else if (i == ft_case_rarrb(stacks->a, stacks->b, temp->curr))
				i = ft_apply_rarrb(stacks, temp->curr, 'a');
			else if (i == ft_case_rrarb(stacks->a, stacks->b, temp->curr))
				i = ft_apply_rrarb(stacks, temp->curr, 'a');
			else
				temp = temp->next;
		}
	}
}

/*
	This function one by one pushes all the elements
	in stack_a to the stack_b, until only three elements
	are left in stack_a. While pushing, it makes sure if
	the stack_b is sorted. When three elements are left,
	it calls the ft_sort_three function to sort left over
	elements in stack_a.
*/
void	ft_sort_start(t_stacks *stacks)
{
	if (ft_stacksize(stacks->a) > 3 && !ft_issorted(stacks->a))
		ft_simulate_stack(stacks, "pb");
	if (ft_stacksize(stacks->a) > 3 && !ft_issorted(stacks->a))
		ft_simulate_stack(stacks, "pb");
	if (ft_stacksize(stacks->a) > 3 && !ft_issorted(stacks->a))
		ft_sort_till_three(stacks);
	if (!ft_issorted(stacks->a))
		ft_simple_algorithm(stacks);
}

/*
	This function is pushing back the elements from stack_b to stack_a
	until stack_b is empty.
*/
void	ft_sort_mid(t_stacks *stacks)
{
	t_stack	**a;
	t_stack	**b;
	t_stack	*temp;
	int		i;

	a = &stacks->a;
	b = &stacks->b;
	while (*b)
	{
		temp = *b;
		i = ft_rotate_type_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*a, *b, temp->curr))
				i = ft_apply_rarb(stacks, temp->curr, 'b');
			else if (i == ft_case_rarrb_a(*a, *b, temp->curr))
				i = ft_apply_rarrb(stacks, temp->curr, 'b');
			else if (i == ft_case_rrarrb_a(*a, *b, temp->curr))
				i = ft_apply_rrarrb(stacks, temp->curr, 'b');
			else if (i == ft_case_rrarb_a(*a, *b, temp->curr))
				i = ft_apply_rrarb(stacks, temp->curr, 'b');
			else
				temp = temp->next;
		}
	}
}

/*Return back the elements in the positions rotating*/
void	ft_sort_end(t_stacks *stacks)
{
	int	i;

	i = ft_find_index(stacks->a, ft_min(stacks->a));
	if (i < ft_stacksize(stacks->a) - i)
	{
		while (stacks->a->curr != ft_min(stacks->a))
			ft_simulate_stack(stacks, "ra");
	}
	else
	{
		while (stacks->a->curr != ft_min(stacks->a))
			ft_simulate_stack(stacks, "rra");
	}
}

/*Print the actions for sort the stacks*/
void	update_stacks(t_stacks *stacks)
{
	ft_sort_start(stacks);
	ft_sort_mid(stacks);
	ft_sort_end(stacks);
}
