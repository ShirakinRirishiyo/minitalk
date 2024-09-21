NAME = libftprintf.a
CC = gcc
SRCS = conversion_tools.c \
		secundarias.c \
		ft_printf.c \
		ft_puthexa.c \

LIBFT_DIR = libft
LIBFT_LIBRARY = libft.a
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_LIBRARY) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@
        

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean 
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
