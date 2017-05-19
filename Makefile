NAME = libftprintf.a
LIB_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj

INC = ft_printf.h.h libft.h
INCLUDE = $(addprefix $(INC_DIR)/,$(INC)
SRC = 	bin_converter.c ft_printf.c hex_converter.c ft_padd_left.c \
		ft_padd_right.c convert_int.c put.c
BIN = ${SRC:%.c=%.o}
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CFLAGS = -Wall -Werror -Wextra

LIBFT = $(LIB_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc $(CFLAGS) -I $(LIB_DIR) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all