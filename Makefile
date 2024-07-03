all: test

test: index.c
	cc -g index.c -lmlx_Linux -Lmlx -Imlx -lXext -lX11 -lm -lz
