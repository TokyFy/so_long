#include <stdlib.h>
#include "mlx/mlx.h"
#include "stdio.h"
#include <unistd.h>
#include <stdint.h>
#include <sys/time.h>

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 320

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
  int h;
  int w;
}				t_data;

typedef struct global {
  void *mlx_ptr;
  void *win_ptr;
  t_data *img;
  t_data** frames;
  unsigned int time;
  int n;
} t_global;

void	put_pixel_img(t_data img, int x, int y, int color)
{
  if(color == 0xFF000000)
    return;
	char	*dst;
  // Fix
  // This asume that the endian is 0
  // This assune that bits_per_pixel is 32
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void fill_pixel_img(t_data img , int color , int width , int height)
{
  int y = 0;
  int x = 0;
  
  while (y < height) {
    x = 0;
    while (x < width) {
      put_pixel_img(img, x, y, color);
      x++;
    }
    y++;
  }
}

unsigned int	get_pixel_img(t_data img, int x, int y) {
	return (*(unsigned int *)((img.addr
			+ (y * img.line_length) + (x * img.bits_per_pixel / 8))));
}

void	put_img_to_img(t_data dst, t_data src, int src_w , int src_h ,int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src_w) {
		j = 0;
		while (j < src_h) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
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
  t_global* g = global;

  static uint64_t	updated_at = 0;
  static int i = 0;
  static int delay = 1;

  if (timestamp_in_ms() - updated_at < (uint64_t)(1000 / 60))
		return 0;
	updated_at = timestamp_in_ms();

  i += 1;
  delay++;

  if(i > 500)
    i = 0;

  /*printf("%d %d\n" , g->n , g->time);*/

  g->time = 0;
  
  fill_pixel_img(*(g->img), 0xCACC95 , WINDOW_WIDTH, WINDOW_HEIGHT);
  if(delay > 2)
  {
    delay = 0;
    g->n++;
    g->n = g->n % 4;
  }
  put_img_to_img(*(g->img) , *(g->frames[g->n]) , (g->frames[g->n])->w , (g->frames[g->n])->h , i , 1 );
  mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img->img, 0, 0);
  usleep(10);
  return 0;
}

int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    t_data	img_data;
  

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");

    img_data.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, &img_data.line_length, &img_data.endian);

    
    t_data  sprite_1;
    sprite_1.img = mlx_xpm_file_to_image(mlx_ptr, "./asset/xmp/idle01.xpm" , &sprite_1.w , &sprite_1.h);
    sprite_1.addr = mlx_get_data_addr(sprite_1.img, &sprite_1.bits_per_pixel, &sprite_1.line_length, &sprite_1.endian);

    t_data  sprite_2;
    sprite_2.img = mlx_xpm_file_to_image(mlx_ptr, "./asset/xmp/idle02.xpm" , &sprite_2.w , &sprite_2.h);
    sprite_2.addr = mlx_get_data_addr(sprite_2.img, &sprite_2.bits_per_pixel, &sprite_2.line_length, &sprite_2.endian);

    t_data  sprite_3;
    sprite_3.img = mlx_xpm_file_to_image(mlx_ptr, "./asset/xmp/idle03.xpm" , &sprite_3.w , &sprite_3.h);
    sprite_3.addr = mlx_get_data_addr(sprite_3.img, &sprite_3.bits_per_pixel, &sprite_3.line_length, &sprite_3.endian);

    t_data  sprite_4;
    sprite_4.img = mlx_xpm_file_to_image(mlx_ptr, "./asset/xmp/idle04.xpm" , &sprite_4.w , &sprite_4.h);
    sprite_4.addr = mlx_get_data_addr(sprite_4.img, &sprite_4.bits_per_pixel, &sprite_4.line_length, &sprite_4.endian);

    t_data** frames = malloc(sizeof(t_data) * 5);
    frames[0] = &sprite_1;
    frames[1] = &sprite_2;
    frames[2] = &sprite_3;
    frames[3] = &sprite_4;


    t_global global;
    global.img = &img_data;
    global.mlx_ptr = mlx_ptr;
    global.win_ptr = win_ptr;
    global.frames = frames;
    global.time = 0;
    global.n = 0;

  

    mlx_loop_hook(mlx_ptr , render_next_frame , &global);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
