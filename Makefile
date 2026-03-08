KUNDE = client
KELLNER = server

CFLAGGEN = -Wall -Wextra -Werror

CC = cc

QUELLE_KUNDE = helper2.c helper.c client.c
QUELLE_KELLNER = helper2.c helper.c server.c

OBJEKTE_KUNDE = $(QUELLE_KUNDE:.c=.o)
OBJEKTE_KELLNER = $(QUELLE_KELLNER:.c=.o)


all: $(KELLNER) $(KUNDE)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

$(KUNDE): $(OBJEKTE_KUNDE)
	$(CC) $(CFLAGGEN) $(OBJEKTE_KUNDE) -o $(KUNDE)

$(KELLNER): $(OBJEKTE_KELLNER)
	$(CC) $(CFLAGGEN) $(OBJEKTE_KELLNER) -o $(KELLNER)

clean: 
	rm -f $(OBJEKTE_KUNDE)
	rm -f $(OBJEKTE_KELLNER)

fclean: clean 
	rm -f $(KUNDE)
	rm -f $(KELLNER)

re: fclean all

.PHONY: all clean flcean re
