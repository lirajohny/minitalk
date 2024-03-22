SRCS = $(wildcard utils/*.c)

OBJS = $(SRCS:.c=.o)
CLIENT = client
SERVER = server
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk.a

all: $(NAME) $(CLIENT) $(SERVER)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(CLIENT):
	$(CC) $(CFLAGS) -o $(CLIENT) client.c $(NAME)

$(SERVER):
	$(CC) $(CFLAGS) -o $(SERVER) server.c $(NAME)

clean:
	$(RM) $(OBJS) $(SERVER) $(CLIENT)

fclean: clean
	$(RM) $(NAME)

re: fclean all
