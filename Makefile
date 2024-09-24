C = gcc
CFLAGS = -Wall -Werror -Wextra -I./libft
LIBFT = ./libft/libftprintf.a

CLIENT = client
SERVER = server

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT) $(CLIENT) $(SERVER) 
	
$(CLIENT): 
	$(C) $(CFLAGS) -o client $(OBJS_SERVER) $(LIBFT)

$(SERVER):
	 $(C) $(CFLAGS) -o server $(OBJS_SERVER) $(LIBFT)


$(OBJS_SERVER): $(SRCS_SERVER)
	$(C) $(CFLAGS) -c $< -o $@

$(OBJS_CLIENT): $(SRCS_CLIENT)
	$(C) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft

clean:
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f server client
	make -C ./libft clean

re: fclean all


