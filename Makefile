MAKEFLAGS   += --no-print-directory

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -Iincludes

OBJ_DIR     = obj
INC_DIR     = includes
HEADERS		= $(INC_DIR)/push_swap.h $(INC_DIR)/libft.h $(INC_DIR)/ft_printf.h

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

STACK		= stack/stack.c

PARSER		= parser/parser.c

BENCH		= bench/bench.c

SORT		= sort/simple/selection_sort.c \
			  sort/medium/chunk_sort.c \
			  sort/complex/turk_sort.c \
			  sort/sort_dispatcher.c

OPERATIONS	= operations/swap.c \
			  operations/push.c \
			  operations/rotate.c \
			  operations/reverse_rotate.c \
			  operations/n_times.c \

UTILS		= utils/push_swap_utils.c \
			  utils/parser_utils.c \
			  utils/stack_utils.c \
			  utils/sort_utils.c \
			  utils/turk_utils.c \

SRCS        = $(OPERATIONS) \
			  $(PARSER) \
			  $(STACK) \
			  $(UTILS) \
			  $(BENCH) \
			  $(SORT) \
			  main.c

			  
			  

########################## DELETE LATERRRRRRRRRRRRRRRRRR
DEBUG		= debug/debug.c
SRCS		+= $(DEBUG)

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
