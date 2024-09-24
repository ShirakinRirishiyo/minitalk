CC = gcc
CFLAGS = -Wall -Werror -Wextra -I../libft
LIBFT = ../libft/libftprintf.a

CLIENT = client
SERVER = server

SRCS_SERVER = server_bonus.c
SRCS_CLIENT = client_bonus.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT):
		$(CC) $(CFLAGS) -o client $(OBJS_CLIENT) $(LIBFT)

$(SERVER):
		$(CC) $(CFLAGS) -o server $(OBJS_SERVER) $(LIBFT)

$(OBJS_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ../libft

clean:
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f server client
	make -C ../libft clean

re: fclean all

