NAME = pipex

LIB = ./Libft/*.c

HEADER = pipex.h ./Libft/libft.h

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pipex.c \
	utils.c\

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) $(HEADER)
	@make -C ./Libft
	$(CC) $(CCFLAGS) $(SRC) $(LIB) -o $(NAME)

all : $(NAME)

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

clean :
	$(RM) $(OBJ)
	@make clean -C ./Libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re 