NAME = libftprintf.a

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

LIB = libft/libft.a

HEADER = ft_printf.h

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) $(HEADER)
	@make -C ./libft
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!!$(NC)"

all : $(NAME)

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@
	@echo "$(YELLOW)Compiling ft_printf 🚀...$(NC)"

clean :
	@$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
