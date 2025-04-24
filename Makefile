SRC			= push_swap.c \
			  ft_applications_rarb_rrarrb.c ft_applications_rrarb_rarrb.c \
			  ft_array_check.c ft_cases_ab.c ft_cases_ba.c \
			  ft_count_algorithm.c ft_error_management.c ft_find.c \
			  ft_free_memory.c ft_move_order.c ft_order.c \
			  ft_print_stacks.c ft_rotate_types.c \
			  ft_simulate_stack_instructions.c ft_simulate_stack.c \
			  ft_sorting_algorithms.c ft_stack_allocation.c ft_stack_order.c \
			  ft_stack_size.c ft_stack_updater.c ft_stacks_initialization.c \


SRC_BONUS	= checker_bonus.c ft_checker_bonus.c ft_error_management_bonus.c \
			  ft_free_memory_bonus.c ft_simulate_stack_bonus.c \
			  ft_simulate_stack_instructions_bonus.c \
			  ft_stack_allocation_bonus.c ft_stacks_initialization_bonus.c

SRCS		= ${addprefix ${PRE_MAN}, ${SRC}}
SRCS_BONUS	= ${addprefix ${PRE_BONUS}, ${SRC_BONUS}}

DIR_OBJS	= objs/

PRE			= srcs/
PRE_MAN		= srcs/mandatory/
PRE_BONUS	= srcs/bonus/

LIBFT_PATH	= ${PRE}libft/
LIBFT		= ${LIBFT_PATH}libft.a

OBJ			= ${SRC:.c=.o}
OBJS		= ${SRCS:.c=.o}
PRE_OBJS	= ${addprefix ${DIR_OBJS}, ${OBJ}}
OBJ_BONUS	= ${SRC_BONUS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
PRE_OBJS_B	= ${addprefix ${DIR_OBJS}, ${OBJ_BONUS}}

NAME		= push_swap
NAME_BONUS	= checker

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

all:		${NAME}

.c.o:
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS} dup_obj ${PRE_OBJS} loading
			@${GCC} ${CFLAGS} -o ${NAME} ${PRE_OBJS} ${LIBFT}
			@echo -ne 'STACK SORTER READY                    \r'
			@echo -ne '\n'

${LIBFT}:
			@make -s -C ${LIBFT_PATH} all

dup_obj:
			@mkdir -p ${DIR_OBJS}
			@mv ${OBJS} ${DIR_OBJS}
dup_obj_b:
			@mkdir -p ${DIR_OBJS}
			@mv ${OBJS_BONUS} ${DIR_OBJS}

loading:
			@echo -ne 'LOADING\033[0;5m...\r'
			@sleep 1
			@echo -ne '\033[0;32m⦗❚❚❚❚❚❚                   ⦘(25%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚            ⦘(50%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚     ⦘(75%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚⦘(100%)\033[0m\r'
			@sleep 0.2

bonus:		${LIBFT} ${OBJS_BONUS} dup_obj_b ${PRE_OBJS_B} loading
			@${GCC} ${CFLAGS} -o ${NAME_BONUS} ${PRE_OBJS_B} ${LIBFT}
			@echo -ne 'CHECKER READY                         \r'
			@echo -ne '\n'

clean:
			@make -s -C ${LIBFT_PATH} clean
			@if [ -d ${DIR_OBJS} ]; then \
				rm -rf ${DIR_OBJS}; \
				echo 'REMOVED OBJS'; \
    		fi

fclean:		clean
			@make -s -C ${LIBFT_PATH} fclean
			@if [ -f ${NAME} ]; then \
				rm -f ${NAME}; \
				echo 'PUSH_SWAP UNINSTALLED'; \
    		fi
			@if [ -f ${NAME_BONUS} ]; then \
				rm -f ${NAME_BONUS}; \
				echo 'CHECKER UNINSTALLED'; \
    		fi

re:			fclean all

reclean:	re
			@make -s clean

.PHONY		= all clean fclean re reclean bonus
