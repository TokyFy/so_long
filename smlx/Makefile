SOURCES = fill_pixel_img.c get_pixel_img.c load_sprite.c put_animation_to_image.c put_img_to_img.c \
			put_pixel_img.c

CC = cc
FLAGS = -g
NAME = libsmlx.a

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

