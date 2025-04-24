/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_ba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:19:30 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:21 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function calculates the required amount of rotation.
	Calculations are done for ra+rb case.
*/
int	ft_case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

/*
	This function calculates the required amount of rotation.
	Calculations are done for rra+rrb case.
*/
int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_stacksize(a) - ft_find_place_a(a, c);
	if ((i < (ft_stacksize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = ft_stacksize(b) - ft_find_index(b, c);
	return (i);
}

/*
	This function calculates the required amount of rotation.
	Calculations are done for ra+rrb case.
*/
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b, c))
		i = ft_stacksize(b) - ft_find_index(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}

/*
	This function calculates the required amount of rotation.
	Calculations are done for rra+rb case.
*/
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_stacksize(a) - ft_find_place_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
