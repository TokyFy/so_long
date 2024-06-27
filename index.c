/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/20 15:15:07 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

# define WINDOW_WIDTH 32 * 32
# define WINDOW_HEIGHT 32 * 16

typedef struct	mlx_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
  int   heigth;
  int   width;
}				t_mlx_image;

typedef struct animation {
  t_mlx_image **frames;
  int length;
  int cdelay;
  int delay;
  int current;
} t_animation ;

typedef struct position {
  int x ; 
  int y ; 
} t_position;


typedef struct state {
  void *mlx_ptr;
  void *win_ptr;
  t_mlx_image *buffer;
  t_animation *animation;
  t_position *main_caracter;
} t_state;

void	put_pixel_img(t_mlx_image img, unsigned int x, unsigned int y, int color)
{
  if(color == 0xFF000000)
    return;

  if(x > img.width || y > img.heigth)
    return;

	char	*dst;
  // Fix
  // This asume that the endian is 0
  // This assune that bits_per_pixel is 32
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

unsigned int	get_pixel_img(t_mlx_image img, int x, int y) {
	return (*(unsigned int *)((img.addr
			+ (y * img.line_length) + (x * img.bits_per_pixel / 8))));
}

void	put_img_to_img(t_mlx_image dst, t_mlx_image src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src.width) {
		j = 0;
		while (j < src.heigth) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void put_animation_to_image(t_mlx_image img , t_animation * animation , uint x , uint y)
{
   put_img_to_img(img, *(animation->frames[animation->current]) , x, y);
  
   animation->cdelay--;

   if(animation->cdelay <= 0)
   {
      animation->current++;
      animation->cdelay = animation->delay;
   }

   if(animation->current > animation->length - 1)
     animation->current = 0;
}


void fill_pixel_img(t_mlx_image img , int color)
{
  int y = 0;
  int x = 0;
  
  while (y < img.heigth) {
    x = 0;
    while (x < img.width) {
      put_pixel_img(img, x, y, color);
      x++;
    }
    y++;
  }
}

void debug_grid(t_mlx_image img , int color)
{
  int y = 0;
  int x = 0;
  
  while (y < img.heigth) {
    x = 0;
    while (x < img.width) {
      if(x % 32 == 0 || y % 32 == 0)
        put_pixel_img(img, x, y, color);
      x++;
    }
    y++;
  }
}

static uint64_t	gettimeofday_ms(void) {
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	timestamp_in_ms(void) {
  static uint64_t  created_at;

	if (created_at == 0)
		created_at = gettimeofday_ms();
	return (gettimeofday_ms() - created_at);
}

int	render_next_frame(void *global)
{
  t_state* g = global;

  static uint64_t	updated_at = 0;
  static int i = 0;
  static int delay = 1;

  if (timestamp_in_ms() - updated_at < (uint64_t)(1000 / 60))
		return 0;
	updated_at = timestamp_in_ms();

  fill_pixel_img(*g->buffer, 0xCACC95);
  debug_grid(*g->buffer, 0x9C9868);

  put_animation_to_image(*g->buffer, g->animation, g->main_caracter->x, g->main_caracter->y);
  mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->buffer->img, 0, 0);
  return 0;
}

t_animation* load_sprite(void* mlx_ptr , char ** xpm , int length)
{
  t_animation* animation = malloc(sizeof(t_animation));
  animation->delay = 5;
  animation->cdelay = 0;
  animation->current = 0;
  animation->length = length;
  
  t_mlx_image** frames = malloc(sizeof(t_mlx_image) * length);

  while (animation->current < animation->length) {
    t_mlx_image *image = malloc(sizeof(t_mlx_image));
    image->img = mlx_xpm_file_to_image(mlx_ptr, xpm[animation->current] , &image->width , &image->heigth);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
    frames[animation->current] = image;
    animation->current++;
  }
  
  animation->frames = frames;
  animation->current = 0;
  return animation;
}

int on_key_up(int keycode, void *param)
{
  // printf("up : %d\n" , keycode);
  return 0;
}

int on_key_down(int keycode, void *global)
{
  // up     122
  // down   115
  // left   113
  // rigth  100
  //
  t_state *g = global;
  int factor = 6;
  if(keycode == 122)
  {
    g->main_caracter->y -= factor ;
  } else if (keycode == 115)
  {
    g->main_caracter->y += factor ;
  } else if (keycode == 113)
  {
    g->main_caracter->x -= factor ;
  } else if(keycode == 100)
  {
    g->main_caracter->x += factor ;
  }
  printf("down : %d\n" , keycode);
}

int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_state global;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "- _ -");

    t_mlx_image buffer;
    buffer.width = WINDOW_WIDTH;
    buffer.heigth = WINDOW_HEIGHT;
    buffer.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    buffer.addr = mlx_get_data_addr( buffer.img , &buffer.bits_per_pixel , &buffer.line_length , &buffer.endian);
   
    global.win_ptr = win_ptr;
    global.mlx_ptr = mlx_ptr;
    global.buffer = &buffer;
 
    // HERE
    char *path[] = {"./asset/xmp/idle01.xpm" , "./asset/xmp/idle02.xpm" , "./asset/xmp/idle03.xpm" , "./asset/xmp/idle04.xpm" , "./asset/xmp/idle05.xpm" , "./asset/xmp/idle06.xpm"};
    global.animation = load_sprite(mlx_ptr, path, 6);

    t_position player;
    player.x = 0;
    player.y = 0;

    global.main_caracter = &player;
    //

    mlx_hook(win_ptr, 03 , 1L<<1 , on_key_up ,&global);
    mlx_hook(win_ptr, 02 , 1L<<0 , on_key_down , &global);
    mlx_loop_hook(mlx_ptr , render_next_frame , &global);
    mlx_loop(mlx_ptr);

    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
