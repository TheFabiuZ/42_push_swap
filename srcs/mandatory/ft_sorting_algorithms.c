/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algorithms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:07:32 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/05/07 18:06:39 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Algorithm for sort a stack of three elements*/
void	ft_simple_algorithm(t_stacks *stacks)
{
	if (stacks->a->curr < stacks->a->next->next->curr && \
		stacks->a->curr < stacks->a->next->curr && \
		stacks->a->next->curr > stacks->a->next->next->curr)
		ft_simulate_stack(stacks, "rra");
	if (stacks->a->curr > stacks->a->next->next->curr && \
		stacks->a->curr > stacks->a->next->curr)
		ft_simulate_stack(stacks, "ra");
	if (stacks->a->curr > stacks->a->next->curr)
		ft_simulate_stack(stacks, "sa");
	if (stacks->a->curr > stacks->a->next->next->curr)
		ft_simulate_stack(stacks, "rra");
}

/*Check if stack is sorted*/
t_bool	ft_issorted(t_stack	*a)
{
	t_stack	*temp;

	temp = a;
	while (temp->next != a)
	{
		if (temp->curr > temp->next->curr)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

/*See what sorting algorithm to use*/
void	sorting_algorithms(t_stacks *stacks, int length)
{
	if (length == 1 || ft_issorted(stacks->a))
		return ;
	if (length == 2)
		if (stacks->a->curr > stacks->a->next->curr)
			ft_simulate_stack(stacks, "sa");
	if (length == 3)
		ft_simple_algorithm(stacks);
	if (length >= 4 && length < 101)
		update_stacks(stacks);
	if (length > 100)
		ft_count_algorithm(stacks);
}
