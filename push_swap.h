/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:24:19 by famirant          #+#    #+#             */
/*   Updated: 2023/05/07 19:46:32 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

// Includes
# include "srcs/libft/h_libft.h"

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
	int		*mov_a;
	int		*mov_b;
}	t_stacks;

// Functions
// = ft_applications_rarb_rrarrb.c =============================================
/*
	This function rotates both stack_a and stack_b
	in the same direction as required amount.
*/
int		ft_apply_rarb(t_stacks *stacks, int c, char s);
/*
	This function rotate both stack_a and stack_b in the
	reverse direction as required amount.
*/
int		ft_apply_rrarrb(t_stacks *stacks, int c, char s);
// = END ft_applications_rarb_rrarrb.c =========================================
// === ft_applications_rrarb_rarrb.c ===========================================
/*
	This function rotate the stack_a in reverse direction,
	the stack_b in oppsite direction of stack_a as required amount.
*/
int		ft_apply_rrarb(t_stacks *stacks, int c, char s);
/*
	This function rotate the stack_b in reverse direction,
	the stack_a in oppsite direction of stack_a as required amount.
*/
int		ft_apply_rarrb(t_stacks *stacks, int c, char s);
// === END ft_applications_rrarb_rarrb.c =======================================
// ===== ft_array_check.c ======================================================
/*Search the lower number in array*/
int		ft_check_lower_array(int *array, int length);
// ===== END ft_array_check.c ==================================================
// ======= ft_cases_ab.c =======================================================
/*
	This function calculates how many times 
	we should rotate the stacks together.
	Because after a certain amoun of rotate, we will
	proceed only with one stack rotation.
*/
int		ft_case_rarb(t_stack *a, t_stack *b, int c);
/*
	This function calculates how many times we should rotate the stacks together.
	Because after a certain amoun of rotate, we will proceed only with one stack
	rotation. Since here we have reverse rotate,rather than index number,
	we check reverse index number which is 
	calculated by list_size - index_number.
*/
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c);
/*
	Again, this function makes similar calculations.
	This function do same calculations for rra+rb case.
*/
int		ft_case_rrarb(t_stack *a, t_stack *b, int c);
/*
	Again, this function makes similar calculations.
	This function do same calculations for ra+rrb case.
*/
int		ft_case_rarrb(t_stack *a, t_stack *b, int c);
// ======= END ft_cases_ab.c ===================================================
// ========= ft_cases_ba.c =====================================================
/*
	This function calculates the required amount of rotation.
	Calculations are done for ra+rb case.
*/
int		ft_case_rarb_a(t_stack *a, t_stack *b, int c);
/*
	This function calculates the required amount of rotation.
	Calculations are done for rra+rrb case.
*/
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
/*
	This function calculates the required amount of rotation.
	Calculations are done for ra+rrb case.
*/
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
/*
	This function calculates the required amount of rotation.
	Calculations are done for rra+rb case.
*/
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
// ========= END ft_cases_ba.c =================================================
// =========== ft_count_algorithm.c ===========================================
/*Algorithm for more than one hundred numbers*/
void	ft_count_algorithm(t_stacks *stacks);
/*Search the higher number than n*/
int		ft_find_higher(t_stack *stack, int n);
// =========== END ft_count_algorithm.c =======================================
// ============= ft_error_management.c =========================================
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
// ============= END ft_error_management.c =====================================
// =============== ft_find.c ===================================================
/*Check the node content at n position in stack*/
int		ft_checknode(t_stack *stack, int n);
/*
	Check the index of stack
	Negative: The number is closer to the end of the stack
*/
int		ft_checkindex(t_stack *stack, int number, int length);
/*This function checks the index of a number in the stack.*/
int		ft_find_index(t_stack *a, int nbr);
/*
	This function finds the correct place of the number in stack_b.
	In other words, it check what index number nbr_push will get 
	after it is being pushed to the stack_b.
*/
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
/*
	This function finds the correct place of the number in stack_a.
	In other words, it check what index number nbr_push will get 
	after it is being pushed to the stack_a.
*/
int		ft_find_place_a(t_stack *stack_a, int nbr_push);
// =============== END ft_find.c ===============================================
// ================= ft_free_memory.c ==========================================
/*Free single stack*/
void	free_stack(t_stack *stack);
/*Free stack_a and stack_b*/
void	free_stacks(t_stacks *stacks);
/*Free the strings in matrix*/
void	free_strs(char **strs);
// ================= END ft_free_memory.c ======================================
// =================== ft_move_order.c =========================================
/*Function count how much movements for push in the other stack*/
int		*ft_countmva(t_stack *a, t_stack *b, int length);
/*
	Count the movement necessary
	for move the element in the first position
*/
int		*ft_countmvb(int length);
/*Absolute the number*/
int		ft_topositive(int number);
/*Array with number of mvs*/
int		*ft_naction(int i, int length, t_stacks *stacks, int *n_action);
//this function convert count in mv
int		ft_convertmv(t_stacks *stacks);
// =================== END ft_move_order.c =====================================
// ===================== ft_order.c ============================================
/*Order number with basic mv rev*/
void	ft_order_b_asic_r(int i, int length, t_stacks *stacks);
/*Order number with basic mv*/
void	ft_order_b_asic(int i, int length, t_stacks *stacks);
/*Order with best actions*/
void	ft_order_b(t_stacks *stacks, int length);
/*Push better number rr*/
void	ft_best_order_both(int ma, int mb, t_stacks *stacks, int n);
/*Check what is the best number to push first*/
void	ft_best_order(t_stacks *stacks, int n);
// ===================== END ft_order.c ========================================
// ======================= ft_print_stacks.c ===================================
/* [TEST]
	Use for print in terminal a single stack in reverse
*/
void	ft_print_stack_reverse(t_stack *stack);
/* [TEST]
	Use for print in terminal a single stack
*/
void	ft_print_stack(t_stack *stack);
/* [TEST]
	Use for print in terminal the stacks | 1 =. reverse
*/
void	ft_print_stacks(t_stacks *stacks, t_bool rev_rule);
// ======================= END ft_print_stacks.c ===============================
// ========================= ft_rotate_types.c =================================
/*
	This function calculate and decides which rotation
	combination is best to use to sort the stack. Of
	course, after rotation there is always one push
	operation is left to do which i embeded to code.
	Function is used during push from B to A.
*/
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
/*
	This function calculate and decides which rotation
	combination is best to use to sort the stack. Of
	course, after rotation there is always one push
	operation is left to do which i embeded to code.
	Function is used during push from A to B.
*/
int		ft_rotate_type_ab(t_stack *a, t_stack *b);
// ========================= END ft_rotate_types.c =============================
// =========================== ft_simulate_stack_instructions.c ================
/* Simulate the rotation(r*) computed on the real stack
	5, 0, 1, 2, 3, 4 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_rotate(t_stack **stack, char stack_name);
/* Simulate the reverse rotation(rr*) computed on the real stack
	1, 2, 3, 4, 5, 0 -> 0, 1, 2, 3, 4, 5
*/
void	ft_simulate_stack_reverserotate(t_stack **stack, char stack_name);
/* Simulate the swap(s*) computed on the real stack
	1, 0, 2, 3 -> 0, 1, 2, 3
*/
void	ft_simulate_stack_swap(t_stack *stack, char stack_name);
/* Simulate the push(p*) computed on the real stack
	pb: a{ 3, 1, 0 } b{   }
	->  a{ 1, 0    } b{ 3 }
	| StackIn =. a, StackOut =. b, to =. b |
*/
void	ft_simulate_stack_push(t_stack **stackIn, t_stack **stackOut, char to);
// =========================== END ft_simulate_stack_instructions.c ============
// ============================= ft_simulate_stack.c ===========================
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
// ============================= END ft_simulate_stack.c =======================
// =============================== ft_sorting_algorithms.c =====================
/*Algorithm for sort a stack of three elements*/
void	ft_simple_algorithm(t_stacks *stacks);
/*Check if stack is sorted*/
t_bool	ft_issorted(t_stack	*a);
/*See what sorting algorithm to use*/
void	sorting_algorithms(t_stacks *stacks, int length);
// =============================== END ft_sorting_algorithms.c =================
// ================================= ft_stack_allocation.c =====================
/*Create a node and fill the prev*/
t_stack	*ft_create_node(t_stack *p_node, int n);
/*Allocate memory to stack*/
void	allocate_memory_to_stack(t_stack **stack, int length);
// ================================= END ft_stack_allocation.c =================
// =================================== ft_stack_order.c ========================
/*Check the content at n position*/
int		ft_check_content_pos(t_stack *stack, int n);
/*
	Order stack s:
	rev = TRUE: Order stack in REVERSE order
*/
void	ft_order_stack(t_stack **stack, t_bool reverse, char name);
// =================================== END ft_stack_order.c ====================
// ===================================== ft_stack_size.c =======================
/*Stack size*/
int		ft_stacksize(t_stack *stack);
/*Last element of the stack*/
t_stack	*ft_stacklast(t_stack *start);
/*This function finds and returns the smallest number in the given stack*/
int		ft_min(t_stack *start);
/*This function finds and returns the biggest number in the given stack*/
int		ft_max(t_stack *start);
// ===================================== END ft_stack_size.c ===================
// ======================================= ft_stack_updater.c ==================
/*Sort until in stack_a remain only three numbers*/
void	ft_sort_till_three(t_stacks *stacks);
/*
	This function one by one pushes all the elements
	in stack_a to the stack_b, until only three elements
	are left in stack_a. While pushing, it makes sure if
	the stack_b is sorted. When three elements are left,
	it calls the ft_sort_three function to sort left over
	elements in stack_a.
*/
void	ft_sort_start(t_stacks *stacks);
/*
	This function is pushing back the elements from stack_b to stack_a
	until stack_b is empty.
*/
void	ft_sort_mid(t_stacks *stacks);
/*Return back the elements in the positions rotating*/
void	ft_sort_end(t_stacks *stacks);
/*Print the actions for sort the stacks*/
void	update_stacks(t_stacks *stacks);
// ======================================= END ft_stack_updater.c ==============
// ========================================= ft_stack_initialization.c =========
/*Initialise the t_stacks struct variable*/
void	ft_initialise_stacks(t_stacks *stacks, int length);
/*Recreate the stack (after allocated memory)*/
void	recreate_stack_a(char **stack, t_stack *a);
// ========================================= END ft_stack_initialization.c =====

#endif