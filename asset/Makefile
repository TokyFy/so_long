SOURCES = ./src/player_run.c ./src/player_idle.c ./src/wall.c \
		  ./src/wall_corner.c ./src/coins.c ./src/ground.c ./src/obstacle.c \
		  ./src/obstacle_1.c  ./src/others.c

CC = cc
FLAGS = -g -Wall -Wextra -Werror
NAME = libassets.a

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

