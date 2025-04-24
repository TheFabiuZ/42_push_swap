/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:55:42 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 20:49:17 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

// Includes
# include "../libft/h_libft.h"

typedef struct s_stack
{
	int				id;
	int				curr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int		length;
	int		moves;
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

// Functions
// = ft_checker_bonus.c ========================================================
/*Check if the operations gived from the stdin order the stack*/
char	*ft_checker(t_stacks *stacks);
// = END ft_checker_bonus.c ====================================================
// === ft_error_management_bonus.c =============================================
/*Print Error & free strs if sprocess is True*/
void	error01(t_bool sprocess, char **strs);
/* Error cases:
	Some arguments aren’t integers and/or there are duplicates.
*/
void	errorcheck_int_dup(char **stack, char *number, t_bool sprocess);
/* Error cases:
	Some arguments aren’t integers, some arguments are
	bigger/less than an integer and/or there are duplicates.
*/
void	errorcheck(char **stack, t_bool sprocess);
// === END ft_error_management_bonus.c =========================================
// ===== ft_free_memory_bonus.c ================================================
/*Free single stack*/
void	free_stack(t_stack *stack);
/*Free stack_a and stack_b*/
void	free_stacks(t_stacks *stacks);
/*Free the strings in matrix*/
void	free_strs(char **strs);
// ===== END ft_free_memory_bonus.c ============================================
// ======= ft_simulate_stack_bonus.c ===========================================
/*Check what stack to rotate*/
void	ft_simulate_stack_rotations(char rot_action, t_stack **a, t_stack **b);
/*Check what stack to swap*/
void	ft_simulate_stack_swappings(char swap_action, t_stack **a, t_stack **b);
/*Check what stack to reverse_rotate*/
void	ft_simulate_stack_rrotations(char rr_action, t_stack **a, t_stack **b);
/*Check what stack to push*/
void	ft_simulate_stack_pushings(char push_action, t_stack **a, t_stack **b);
/*Simulate the actions computed on the real stack*/
void	ft_simulate_stack(t_stacks *stacks, char *action);
// ======= END ft_simulate_stack_bonus.c =======================================
// ========= ft_simulate_stack_instructions_bonus.c ============================
/* Simulate the rotation(r*) computed on the real stack
	5, 0, 1, 2, 3, 4 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_rotate(t_stack **stack);
/* Simulate the reverse rotation(rr*) computed on the real stack
	1, 2, 3, 4, 5, 0 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_reverserotate(t_stack **stack);
/* Simulate the swap(s*) computed on the real stack
	1, 0, 2, 3 -> 0, 1, 2, 3
*/
void	ft_simulate_stack_swap(t_stack *stack);
/* Simulate the push(p*) computed on the real stack
	pb: a{ 3, 1, 0 } b{   }
	->  a{ 1, 0    } b{ 3 }
	| StackIn = a, StackOut = b, to = b |
*/
void	ft_simulate_stack_push(t_stack **stackIn, t_stack **stackOut);
// ========= END ft_simulate_stack_instructions_bonus.c ========================
// =========== ft_stack_allocation.c ===========================================
/*Create a node and fill the prev*/
t_stack	*ft_create_node(t_stack *p_node, int n);
/*Allocate memory to stack*/
void	allocate_memory_to_stack(t_stack **stack, int length);
// =========== END ft_stack_allocation.c =======================================
// ============= ft_stack_initialization.c =====================================
/*Initialise the t_stacks struct variable*/
void	ft_initialise_stacks(t_stacks *stacks, int length);
/*Recreate the stack (after allocated memory)*/
void	recreate_stack_a(char **stack, t_stack *a);
// ============= END ft_stack_initialization.c =================================

#endif