#include "../cub3d.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void    game_render(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	return ;
}

void	game_start(t_data *data)
{
	int	x;
	int	y;

	
	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			game_render(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, 
		data->img.img, 0, 0);
}
