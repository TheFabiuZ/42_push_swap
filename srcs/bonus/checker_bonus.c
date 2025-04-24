/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:00:33 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 23:32:29 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_subprocess(char *numbers, int length, char ***stack)
{
	*stack = ft_split(numbers, ' ');
	length -= 1;
	while ((*stack)[length])
		length++;
	return (length);
}

void	checker(int length, char **argv)
{
	t_stacks	stacks;
	t_bool		sprocess;
	char		**stack;

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
	ft_printf("%s", ft_checker(&stacks));
	free_stacks(&stacks);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		checker(argc - 1, argv + 1);
	return (0);
}
