/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:35:44 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:07 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function calculate and decides which rotation
	combination is best to use to sort the stack. Of
	course, after rotation there is always one push
	operation is left to do which i embeded to code.
	Function is used during push from B to A.
*/
int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*start;

	start = b;
	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->curr);
	while (tmp->next != start)
	{
		if (i > ft_case_rarb_a(a, b, tmp->curr))
			i = ft_case_rarb_a(a, b, tmp->curr);
		if (i > ft_case_rrarrb_a(a, b, tmp->curr))
			i = ft_case_rrarrb_a(a, b, tmp->curr);
		if (i > ft_case_rarrb_a(a, b, tmp->curr))
			i = ft_case_rarrb_a(a, b, tmp->curr);
		if (i > ft_case_rrarb_a(a, b, tmp->curr))
			i = ft_case_rrarb_a(a, b, tmp->curr);
		tmp = tmp->next;
	}
	return (i);
}

/*
	This function calculate and decides which rotation
	combination is best to use to sort the stack. Of
	course, after rotation there is always one push
	operation is left to do which i embeded to code.
	Function is used during push from A to B.
*/
int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*start;

	start = a;
	tmp = a;
	i = ft_case_rrarrb(a, b, a->curr);
	while (tmp->next != start)
	{
		if (i > ft_case_rarb(a, b, tmp->curr))
			i = ft_case_rarb(a, b, tmp->curr);
		if (i > ft_case_rrarrb(a, b, tmp->curr))
			i = ft_case_rrarrb(a, b, tmp->curr);
		if (i > ft_case_rarrb(a, b, tmp->curr))
			i = ft_case_rarrb(a, b, tmp->curr);
		if (i > ft_case_rrarb(a, b, tmp->curr))
			i = ft_case_rrarb(a, b, tmp->curr);
		tmp = tmp->next;
	}
	return (i);
}
