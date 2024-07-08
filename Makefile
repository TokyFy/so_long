all: test

test:
	cc -g index.c  ./smlx/libsmlx.a ./libft/libft.a -lmlx_Linux -Lmlx -Imlx -lXext -lX11 -lm -lz
