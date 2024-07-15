all: test

libsmlx.a:
	$(MAKE) -C ./smlx

libft.a:
	$(MAKE) -C ./libft

test: libsmlx.a libft.a index.c engime/maps.c
	cc -g index.c engime/maps.c  ./smlx/libsmlx.a ./libft/libft.a -lmlx_Linux -Lmlx -Imlx -lXext -lX11 -lm -lz
