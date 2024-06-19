#include <stdlib.h>
#include "mlx/mlx.h"

# define WINDOW_WIDTH 665
# define WINDOW_HEIGHT 556

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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


int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    t_data	img_data;
    t_data  sprite_data;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");

    img_data.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

    img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, &img_data.line_length, &img_data.endian);

   
    fill_pixel_img(img_data, 0xCACC95 , WINDOW_WIDTH, WINDOW_HEIGHT);
    
    int sprite_w = 0;
    int sprite_h = 0;

    sprite_data.img = mlx_xpm_file_to_image(mlx_ptr, "./c_idle.xpm" , &sprite_w , &sprite_h);
    sprite_data.addr = mlx_get_data_addr(sprite_data.img, &sprite_data.bits_per_pixel, &sprite_data.line_length, &sprite_data.endian);

    put_img_to_img(img_data, sprite_data, sprite_w, sprite_h, 0, 0);

    mlx_put_image_to_window(mlx_ptr, win_ptr, img_data.img, 0, 0);

    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
