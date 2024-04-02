#include "../cub3d.h"
#include <stdio.h>

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

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->map.p_x/TILE_SIZE;
	y = data->map.p_y/TILE_SIZE;
	if (data->map.map_data[y][x-1] == '0')
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE) - 1;
		data->map.p_y = (data->map.p_y/TILE_SIZE);
	}
	else
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE);
		data->map.p_y = (data->map.p_y/TILE_SIZE);	
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->map.p_x/TILE_SIZE;
	y = data->map.p_y/TILE_SIZE;
	if (data->map.map_data[y][x+1] == '0')
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE) + 1;
		data->map.p_y = (data->map.p_y/TILE_SIZE);
	}
	else
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE);
		data->map.p_y = (data->map.p_y/TILE_SIZE);	
	}
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->map.p_x/TILE_SIZE;
	y = data->map.p_y/TILE_SIZE;
	if (data->map.map_data[y-1][x] == '0')
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE);
		data->map.p_y = (data->map.p_y/TILE_SIZE) - 1;
	}
	else
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE);
		data->map.p_y = (data->map.p_y/TILE_SIZE);	
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->map.p_x/TILE_SIZE;
	y = data->map.p_y/TILE_SIZE;
	if (data->map.map_data[y+1][x] == '0')
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE);
		data->map.p_y = (data->map.p_y/TILE_SIZE) + 1;
	}
	else
	{
		data->map.p_x = (data->map.p_x/TILE_SIZE);
		data->map.p_y = (data->map.p_y/TILE_SIZE);	
	}
}

int	key_press(int keycode, t_data *data)
{
	printf("key = %d\n", keycode);
	if (keycode == ESC_KEY)
		close_press(data);
	else if (keycode == A_KEY)
		move_left(data);
	else if (keycode == D_KEY)
		move_right(data);
	else if (keycode == W_KEY)
		move_up(data);
	else if (keycode == S_KEY)
		move_down(data);
	else if (keycode == R_KEY)
		data_set(data);
	else
		return (0);
	mlx_clear_window(data->mlx, data->win);
	//print_array(data->map.map_data);
	game_start(data);
	return (0);
}

int	mouse_track(int x, int y, t_data *data)
{
		(void)data;
		if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
		{
			//TO DO For Mouse
			//game_start(data);
		}
	return (0);
}
