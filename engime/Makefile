SOURCES = ./collision.c ./fps.c ./frames.c ./keys.c ./maps.c ./utils.c ./worlds.c

CC = cc
FLAGS = -g
NAME = libengime.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : %.o : %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

lib : all clean

re : fclean all

