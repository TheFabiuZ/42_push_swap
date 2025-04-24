/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:04:34 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 19:47:49 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Order number with basic mv rev*/
void	ft_order_b_asic_r(int i, int length, t_stacks *stacks)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	i = length;
	while (i > 0)
	{
		if ((*a)->curr > ft_checknode(*b, i) && \
		(*a)->curr < ft_checknode(*b, i - 1))
		{
			while (i++ < length)
				ft_simulate_stack(stacks, "rrb");
			ft_simulate_stack(stacks, "pb");
			return ;
		}
		i--;
	}
}

/*Order number with basic mv*/
void	ft_order_b_asic(int i, int length, t_stacks *stacks)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	while (i < length / 2)
	{
		if ((*a)->curr > ft_checknode(*b, i) && \
		(*a)->curr < ft_checknode(*b, i - 1))
		{
			while (i-- > 0)
				ft_simulate_stack(stacks, "rb");
			ft_simulate_stack(stacks, "pb");
			return ;
		}
		i++;
	}
	if (i)
		ft_order_b_asic_r(i, length, stacks);
}

/*Order with best actions*/
void	ft_order_b(t_stacks *stacks, int length)
{
	t_stack	**a;
	t_stack	**b;

	a = &stacks->a;
	b = &stacks->b;
	if ((*a)->curr < ft_min(*b))
	{
		while (ft_checkindex(*b, ft_min(*b), length) > -1)
			ft_simulate_stack(stacks, "rb");
		while (ft_checkindex(*b, ft_min(*b), length) < -1)
			ft_simulate_stack(stacks, "rrb");
		ft_simulate_stack(stacks, "pb");
		return ;
	}
	if ((*a)->curr > ft_max(*b))
	{
		while (ft_checkindex(*b, ft_max(*b), length) > 0)
			ft_simulate_stack(stacks, "rb");
		while (ft_checkindex(*b, ft_max(*b), length) < 0)
			ft_simulate_stack(stacks, "rrb");
		ft_simulate_stack(stacks, "pb");
		return ;
	}
	ft_order_b_asic(0, length, stacks);
}

/*Push better number rr*/
void	ft_best_order_both(int ma, int mb, t_stacks *stacks, int n)
{
	if (ft_stacksize(stacks->a) > 1)
	{
		ma = stacks->mov_a[ft_check_content_pos(stacks->a, n) - 1];
		mb = stacks->mov_b[ft_check_content_pos(stacks->a, n) - 1];
	}
	while (ma < 0 && mb < 0)
	{
		ft_simulate_stack(stacks, "rrr");
		ma++;
		mb++;
	}
	while (ma > 1 && mb > 0)
	{
		ft_simulate_stack(stacks, "rr");
		ma--;
		mb--;
	}
}

/*Check what is the best number to push first*/
void	ft_best_order(t_stacks *stacks, int n)
{
	ft_best_order_both(0, 0, stacks, n);
	while (ft_checkindex(stacks->a, n, ft_stacksize(stacks->a)) > 0)
		ft_simulate_stack(stacks, "ra");
	while (ft_checkindex(stacks->a, n, ft_stacksize(stacks->a)) < 0)
		ft_simulate_stack(stacks, "rra");
	ft_order_b(stacks, ft_stacksize(stacks->b));
}
