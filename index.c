#include <stdlib.h>
#include "mlx/mlx.h"
#include <unistd.h>
#include <sys/time.h>

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 320


int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");


    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
