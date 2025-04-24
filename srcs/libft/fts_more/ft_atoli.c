/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thefabiuz <thefabiuz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:59:50 by famirant          #+#    #+#             */
/*   Updated: 2023/03/23 17:38:56 by thefabiuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_more.h"

long int	ft_atoli(const char *nptr)
{
	int			i;
	int			is_negative;
	long int	number;

	number = 0;
	is_negative = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	if (is_negative % 2)
		number *= -1;
	return (number);
}

/*Try to do ft_atoli | 1 = Error*/
t_bool	ft_atoli_error(const char *nptr)
{
	int			i;
	int			is_negative;
	long int	number;

	number = 0;
	is_negative = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			is_negative++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		number = (number * 10) + (nptr[i++] - '0');
	if (is_negative % 2)
		number *= -1;
	if (nptr[i] || \
		(i > 0 && !nptr[i] && (nptr[i - 1] == '+' || nptr[i - 1] == '-')))
		return (1);
	return (0);
}
