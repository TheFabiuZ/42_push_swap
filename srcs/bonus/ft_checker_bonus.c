/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:26:23 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 23:33:45 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Check order of stack*/
t_bool	ft_checkorder(t_stack *stack)
{
	t_stack	*temp;

	temp = stack->prev;
	while (stack != temp)
	{
		if (stack->curr > stack->next->curr)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

t_bool	ft_conditions_check_op(t_stacks *stacks, char *operations)
{
	if (!ft_strncmp(operations, "sa\n", 3))
		ft_simulate_stack(stacks, "sa");
	else if (!ft_strncmp(operations, "sb\n", 3))
		ft_simulate_stack(stacks, "sb");
	else if (!ft_strncmp(operations, "ss\n", 3))
		ft_simulate_stack(stacks, "ss");
	else if (!ft_strncmp(operations, "ra\n", 3))
		ft_simulate_stack(stacks, "ra");
	else if (!ft_strncmp(operations, "rb\n", 3))
		ft_simulate_stack(stacks, "rb");
	else if (!ft_strncmp(operations, "rr\n", 3))
		ft_simulate_stack(stacks, "rr");
	else if (!ft_strncmp(operations, "rrr\n", 4))
		ft_simulate_stack(stacks, "rrr");
	else if (!ft_strncmp(operations, "rra\n", 4))
		ft_simulate_stack(stacks, "rra");
	else if (!ft_strncmp(operations, "rrb\n", 4))
		ft_simulate_stack(stacks, "rrb");
	else if (!ft_strncmp(operations, "pb\n", 3))
		ft_simulate_stack(stacks, "pb");
	else if (!ft_strncmp(operations, "pa\n", 3))
		ft_simulate_stack(stacks, "pa");
	else
		return (TRUE);
	return (FALSE);
}

/*Check if the operations gived from the stdin order the stack*/
char	*ft_checker(t_stacks *stacks)
{
	char	*operations;

	operations = "1";
	while (operations)
	{
		operations = get_next_line(0);
		if (operations)
		{
			if (ft_conditions_check_op(stacks, operations) == TRUE)
			{
				free(operations);
				ft_putstr_fd("Error\n", 2);
				return ("");
			}
			free(operations);
		}
	}
	if (!stacks->a || stacks->b || ft_checkorder(stacks->a))
		return ("KO\n");
	return ("OK\n");
}
