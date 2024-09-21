NAME = libftprintf.a
CC = gcc

# Source files for libftprintf
SRCS = conversion_tools.c \
       secundarias.c \
       ft_printf.c \
       ft_puthexa.c \
       get_next_line.c \
       get_next_line_utils.c \
       ft_bzero.c \
       ft_calloc.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_itoa.c \
       ft_atoi.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_strdup.c \
       ft_putstr_fd.c \
       ft_split.c \
       ft_strchr.c \
       ft_striteri.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strmapi.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_strlen.c \
       ft_strlcpy.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compilation flags
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
