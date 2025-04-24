/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:23:20 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 21:30:07 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_subprocess(char *numbers, int length, char ***stack)
{
	*stack = ft_split(numbers, ' ');
	length -= 1;
	while ((*stack)[length])
		length++;
	return (length);
}

void	push_swap(int length, char **argv)
{
	t_stacks	stacks;
	char		**stack;
	t_bool		sprocess;

	stack = argv;
	sprocess = FALSE;
	if (length == 1)
	{
		length = ft_subprocess(*argv, length, &stack);
		sprocess = TRUE;
	}
	errorcheck(stack, sprocess);
	ft_initialise_stacks(&stacks, length);
	allocate_memory_to_stack(&stacks.a, length);
	recreate_stack_a(stack, stacks.a);
	if (sprocess)
		free_strs(stack);
	sorting_algorithms(&stacks, length);
	free_stacks(&stacks);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc - 1, argv + 1);
	return (0);
}
