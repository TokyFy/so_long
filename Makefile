

NAME=so_long

all: $(NAME)

libsmlx.a:
	$(MAKE) -C ./smlx

libft.a:
	$(MAKE) bonus -C ./libft

libengime.a:
	$(MAKE) -C ./engime

clean:
	$(MAKE) fclean -C ./smlx
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./engime

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): libsmlx.a libft.a index.c libengime.a
	cc -g index.c  ./engime/libengime.a ./smlx/libsmlx.a ./libft/libft.a  -lmlx_Linux -Lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME)
