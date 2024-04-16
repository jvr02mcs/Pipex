NAME = pipex

GREEN = \033[0;32m
LIGHT_GREEN = \033[0;42m
RED = \033[0;31m
NC = \033[0m

LIB = ./ft_printf/libftprintf.a

HEADER = pipex.h ./ft_printf/ft_printf.h

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pipex.c\

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) $(HEADER)
	@make -C ./ft_printf
	@$(CC) $(CCFLAGS) $(SRC) ./ft_printf/libft/*.c ./ft_printf/*.c -o $(NAME)
	@echo "$(GREEN)pipex compiled!!$(NC)"
	@echo "$(GREEN)Compilation success!!!$(NC)"
all : $(NAME)
%.o : %.c
	@$(CC) -c $(CCFLAGS) $< -o $@
	@echo "$(LIGHT_GREEN)     ---------------------     $(NC)     "
	@echo "$(LIGHT_GREEN)    |  Compiling pipex ...|    $(NC)    "
	@echo "$(LIGHT_GREEN)     ---------------------     $(NC)     "
	@echo "$(LIGHT_GREEN)      |                 |      $(NC)      "
	@echo "$(LIGHT_GREEN)      |                 |      $(NC)      "
	@echo "$(LIGHT_GREEN)      |                 |      $(NC)      "

clean:
	@make clean -C ./ft_printf
	@$(RM) $(OBJ)
	@echo "$(RED)pipex cleaned$(NC)"

fclean: clean
	@@make fclean -C ./ft_printf
	@$(RM) $(NAME)
	@echo "$(RED)fclean pipex$(NC)"

re: fclean all

.PHONY: all clean fclean re
