#include <stdlib.h>
#include "mlx/mlx.h"
#include <unistd.h>
#include <sys/time.h>

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

int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "- _ -");

    t_mlx_image buffer;
    buffer.width = WINDOW_WIDTH;
    buffer.heigth = WINDOW_HEIGHT;
    buffer.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    buffer.addr = mlx_get_data_addr( buffer.img , &buffer.bits_per_pixel , &buffer.line_length , &buffer.endian);
   
    fill_pixel_img(buffer, 0xCACC95);
    debug_grid(buffer, 0x9C9868);

    mlx_put_image_to_window(mlx_ptr, win_ptr, buffer.img, 0, 0);

    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
