/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulate_stack_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:14:52 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/26 16:19:05 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Check what stack to rotate*/
void	ft_simulate_stack_rotations(char rot_action, t_stack **a, t_stack **b)
{
	if (rot_action == 'a')
		ft_simulate_stack_rotate(a);
	if (rot_action == 'b')
		ft_simulate_stack_rotate(b);
	if (rot_action == 'r')
	{
		ft_simulate_stack_rotate(a);
		ft_simulate_stack_rotate(b);
	}
}

/*Check what stack to swap*/
void	ft_simulate_stack_swappings(char swap_action, t_stack **a, t_stack **b)
{
	if (swap_action == 'a')
		ft_simulate_stack_swap(*a);
	if (swap_action == 'b')
		ft_simulate_stack_swap(*b);
	if (swap_action == 's')
	{
		ft_simulate_stack_swap(*a);
		ft_simulate_stack_swap(*b);
	}
}

/*Check what stack to reverse_rotate*/
void	ft_simulate_stack_rrotations(char rr_action, t_stack **a, t_stack **b)
{
	if (rr_action == 'a')
		ft_simulate_stack_reverserotate(a);
	if (rr_action == 'b')
		ft_simulate_stack_reverserotate(b);
	if (rr_action == 'r')
	{
		ft_simulate_stack_reverserotate(a);
		ft_simulate_stack_reverserotate(b);
	}
}

/*Check what stack to push*/
void	ft_simulate_stack_pushings(char push_action, t_stack **a, t_stack **b)
{
	if (push_action == 'a')
		ft_simulate_stack_push(b, a);
	if (push_action == 'b')
		ft_simulate_stack_push(a, b);
}

/*Simulate the actions computed on the real stack*/
void	ft_simulate_stack(t_stacks *stacks, char *action)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	if (*action == 'r' && action[2] == 0)
		ft_simulate_stack_rotations(action[1], a, b);
	if (*action == 'r' && action[1] == 'r' && action[2] != 0)
		ft_simulate_stack_rrotations(action[2], a, b);
	if (*action == 's')
		ft_simulate_stack_swappings(action[1], a, b);
	if (*action == 'p')
		ft_simulate_stack_pushings(action[1], a, b);
	stacks->moves++;
}
