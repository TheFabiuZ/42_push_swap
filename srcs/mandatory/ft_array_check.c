/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:56:53 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 18:58:46 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Search the lower number in array*/
int	ft_check_lower_array(int *array, int length)
{
	int	lower;

	lower = array[length];
	while (length >= 0)
	{
		if (array[length] < lower)
			lower = array[length];
		length--;
	}
	return (lower);
}
