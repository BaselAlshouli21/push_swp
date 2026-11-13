MAKEFLAGS += --no-print-directory

CC = cc
HEADER_DIR = ../includes
FLAGS = -Wall -Werror -Wextra -I$(HEADER_DIR)
NAME = libftprintf.a
OBJ_DIR = obj

SRCS = ft_printf.c \
	utils/ft_printf_utils.c \
	utils/ft_parser_utils.c \
	utils/ft_renderer_utils.c \
	renderer/ft_renderer.c \
	renderer/ft_render_flags.c \
	renderer/ft_render_specifiers.c \
	parser/ft_parser.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c $(HEADER_DIR)/ft_printf.h
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f printf

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
