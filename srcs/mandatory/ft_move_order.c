/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:45:22 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 19:41:26 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Function count how much movements for push in the other stack*/
int	*ft_countmva(t_stack *a, t_stack *b, int length)
{
	t_stack	*start_a;
	int		*move_a;
	int		a_len;

	a_len = 0;
	start_a = a;
	move_a = malloc(sizeof(int) * length);
	while (start_a != a->next)
	{
		move_a[a_len++] = ft_checkindex(b, \
							ft_find_higher(b, a->curr), ft_stacksize(b)) + 1;
		a = a->next;
	}
	move_a[a_len] = ft_checkindex(b, ft_find_higher(b, a->curr), \
									ft_stacksize(b)) + 1;
	return (move_a);
}

/*
	Count the movement necessary
	for move the element in the first position
*/
int	*ft_countmvb(int length)
{
	int	*move_b;
	int	position;
	int	index;

	move_b = malloc(sizeof(int) * length);
	index = 0;
	position = 0;
	while (position < length / 2)
		move_b[index++] = position++;
	while (position < length)
		move_b[index++] = position++ - length;
	return (move_b);
}

/*Absolute the number*/
int	ft_topositive(int number)
{
	if (number < 0)
		number = -number;
	return (number);
}

/*Array with number of mvs*/
int	*ft_naction(int i, int length, t_stacks *stacks, int *n_action)
{
	while (i < length)
	{
		if (stacks->mov_a[i] < 0 && stacks->mov_b[i] < 0)
		{
			if (stacks->mov_b[i] < stacks->mov_a[i])
				n_action[i] = ft_topositive(stacks->mov_b[i]);
			else
				n_action[i] = ft_topositive(stacks->mov_a[i]);
		}
		else if (stacks->mov_b[i] < 0 || stacks->mov_a[i] < 0)
			n_action[i] = ft_topositive(stacks->mov_a[i]) \
			+ ft_topositive(stacks->mov_b[i]);
		else
		{
			if (stacks->mov_b[i] > stacks->mov_a[i])
				n_action[i] = stacks->mov_b[i];
			else
				n_action[i] = stacks->mov_a[i];
		}
		i++;
	}
	return (n_action);
}

//this function convert count in mv
int	ft_convertmv(t_stacks *stacks)
{
	int	index;
	int	length;
	int	*n_action;
	int	start;

	length = ft_stacksize(stacks->a);
	n_action = malloc(sizeof(int) * length);
	n_action = ft_naction(0, length, stacks, n_action);
	start = ft_check_lower_array(n_action, length - 1);
	index = 0;
	while (n_action[index] != start)
		index++;
	free(n_action);
	return (ft_checknode(stacks->a, index));
}
