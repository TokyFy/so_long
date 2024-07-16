all: test

libsmlx.a:
	$(MAKE) -C ./smlx

libft.a:
	$(MAKE) bonus -C ./libft

libengime.a:
	$(MAKE) -C ./engime

test: libsmlx.a libft.a index.c libengime.a
	cc -g index.c  ./engime/libengime.a ./smlx/libsmlx.a ./libft/libft.a  -lmlx_Linux -Lmlx -Imlx -lXext -lX11 -lm -lz
