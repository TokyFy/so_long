# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/07/05 11:17:53 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = fill_pixel_img.c get_pixel_img.c load_sprite.c put_animation_to_image.c put_img_to_img.c \
			put_pixel_img.c

CC = cc
FLAGS =
NAME = libsmlx.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : %.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

lib : all clean

re : fclean all

