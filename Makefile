CLIENT = client
SERVER = server
LIBNAME = libft/libft.a

CFLAGGEN = -Wall -Wextra -Werror -Wpedantic

CC = cc

QUELLE_CLIENT = client.c
QUELLE_SERVER = server.c

OBJEKT_CLIENT = $(QUELLE_CLIENT:.c=.o)
OBJEKT_SERVER = $(QUELLE_SERVER:.c=.o)


all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

libft/libft.a:
	cd libft && make

$(CLIENT): $(OBJEKT_CLIENT) libft/libft.a
	$(CC) $(CFLAGGEN) $(OBJEKT_CLIENT) $(LIBNAME) -o $(CLIENT)

$(SERVER): $(OBJEKT_SERVER) libft/libft.a
	$(CC) $(CFLAGGEN) $(OBJEKT_SERVER) $(LIBNAME) -o $(SERVER)

clean: 
	rm -f $(OBJEKT_CLIENT)
	rm -f $(OBJEKT_SERVER)
	cd libft && make clean

fclean: clean 
	rm -f $(CLIENT)
	rm -f $(SERVER)
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean flcean re
