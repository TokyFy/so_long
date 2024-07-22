NAME = so_long
SRCS = index.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBENGIME = ./engime/libengime.a
LIBSMLX = ./smlx/libsmlx.a
LIBMLX =  ./mlx/libmlx.a
LIBMLX_URL = https://cdn.intra.42.fr/document/document/26489/minilibx-linux.tgz
LIBMLX_TGZ = minilibx-linux

CC = cc
CFLAGS = -g -Imlx 
LDFLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(LIBSMLX): 
	$(MAKE) -C ./smlx

$(LIBENGIME): 
	$(MAKE) -C ./engime

$(NAME): $(OBJS) $(LIBFT) $(LIBSMLX) $(LIBENGIME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBENGIME) $(LIBSMLX) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C ./smlx
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./engime
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus : all

test :
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map.ber

configure:
	rm -rf mlx
	wget -nc $(LIBMLX_URL)
	tar -xzf $(LIBMLX_TGZ).tgz
	mv $(LIBMLX_TGZ) mlx
	$(MAKE) -C ./mlx
	rm -rf $(LIBMLX_TGZ).tgz

.PHONY: clean fclean re
