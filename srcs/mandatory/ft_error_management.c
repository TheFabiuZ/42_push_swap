/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:52:19 by thefabiuz         #+#    #+#             */
/*   Updated: 2023/04/05 11:57:16 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Print Error & free strs if sprocess is True*/
void	error01(t_bool sprocess, char **strs)
{
	if (sprocess)
		free_strs(strs);
	write(2, "Error\n", 6);
	exit(1);
}

/* Error cases:
	Some arguments aren’t integers and/or there are duplicates.
*/
void	errorcheck_int_dup(char **stack, char *number, t_bool sprocess)
{
	int	n;

	n = 0;
	while (number[n])
	{
		if ((number[n] < '0' || number[n] > '9') && number[n] != '-'\
			&& number[n] != '+')
			error01(sprocess, stack);
		n++;
	}
	n = 1;
	while (stack[n])
	{
		if (ft_atoli(number) == ft_atoli(stack[n]))
			error01(sprocess, stack);
		n++;
	}
}

/* Error cases:
	Some arguments aren’t integers, some arguments are
	bigger/less than an integer and/or there are duplicates.
*/
void	errorcheck(char **stack, t_bool sprocess)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		errorcheck_int_dup(stack + i, stack[i], sprocess);
		if (ft_atoli(stack[i]) > 2147483647 || \
			ft_atoli(stack[i]) < -2147483648 || ft_atoli_error(stack[i]))
			error01(sprocess, stack);
		i++;
	}
}
