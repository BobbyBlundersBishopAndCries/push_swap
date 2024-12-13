CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =  stack_definition_utils.c main.c ft_split.c ft_string_fd.c functions_a.c functions_b.c get_mid_index_value.c  sort.c utils_helper.c ft_substr.c s_algo.c
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : clean re all fclean