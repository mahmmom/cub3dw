#include "../cub3d.h"

int	close_press(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

// int	mouse_press(int keycode, int x, int y, t_data *data)
// {
// 	(void)x;
// 	(void)y;
// 	if (keycode == MOUSE_UP)
// 	{
// 		data-> *= 0.70;
// 	}
// 	else if (keycode == MOUSE_DOWN)
// 	{
// 		data-> *= 1.80;
// 	}
	
// 	game_start(data);
// 	return (0);
// }

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_press(data);
	else if (keycode == A_KEY)
		data->shift_x += 0.5;
	else if (keycode == D_KEY)
		data->shift_x -= 0.5;
	else if (keycode == W_KEY)
		data->shift_y -= 0.5;
	else if (keycode == S_KEY)
		data->shift_y += 0.5;
	else if (keycode == R_KEY)
		data_set(data);
	game_start(data);
	return (0);
}

int	julia_track(int x, int y, t_data *fractal)
{
		if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
		{
			//TO DO For Mouse
			//game_start(fractal);
		}
	return (0);
}
