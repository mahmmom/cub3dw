#include "../cub3d.h"

void	ft_move_hori(t_data *data, int keycode)
{
	if (keycode == 0) // Move left
	{
		double new_posx = data->posx - data->planex * data->move_speed;
		double new_posy = data->posy - data->planey * data->move_speed;

		if (data->map.map_data[(int)new_posy][(int)data->posx] != '1')
			data->posx = new_posx;
		if (data->map.map_data[(int)data->posy][(int)new_posx] != '1')
			data->posy = new_posy;
	}
	if (keycode == 2) // Move right
	{
		double new_posx = data->posx + data->planex * data->move_speed;
		double new_posy = data->posy + data->planey * data->move_speed;

		if (data->map.map_data[(int)new_posy][(int)data->posx] != '1')
			data->posx = new_posx;
		if (data->map.map_data[(int)data->posy][(int)new_posx] != '1')
			data->posy = new_posy;
	}
}

void	ft_move_vert(t_data *data, int keycode)
{
	if (keycode == 13) // Move forward
	{
		double new_posx = data->posx + data->dirx * data->move_speed;
		double new_posy = data->posy + data->diry * data->move_speed;

		if (data->map.map_data[(int)new_posy][(int)data->posx] != '1')
			data->posx = new_posx;
		if (data->map.map_data[(int)data->posy][(int)new_posx] != '1')
			data->posy = new_posy;
	}
	if (keycode == 1) // Move backward
	{
		double new_posx = data->posx - data->dirx * data->move_speed;
		double new_posy = data->posy - data->diry * data->move_speed;

		if (data->map.map_data[(int)new_posy][(int)data->posx] != '1')
			data->posx = new_posx;
		if (data->map.map_data[(int)data->posy][(int)new_posx] != '1')
			data->posy = new_posy;
	}
}

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(data->rotate)
		- data->diry * sin(data->rotate);
	data->diry = olddirx * sin(data->rotate)
		+ data->diry * cos(data->rotate);
	oldplanex = data->planex;
	data->planex = data->planex * cos(data->rotate)
		- data->planey * sin(data->rotate);
	data->planey = oldplanex * sin(data->rotate)
		+ data->planey * cos(data->rotate);
}

void	ft_rotate(t_data *data, int keycode)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	oldplanex = data->planex;
	if (keycode == 124)
	{
		data->dirx = data->dirx * cos(-data->rotate)
			- data->diry * sin(-data->rotate);
		data->diry = olddirx * sin(-data->rotate)
			+ data->diry * cos(-data->rotate);
		data->planex = data->planex * cos(-data->rotate)
			- data->planey * sin(-data->rotate);
		data->planey = oldplanex * sin(-data->rotate)
			+ data->planey * cos(-data->rotate);
	}
	if (keycode == 123)
		rotate_left(data);
}

int	cub_key_press(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 1)
		ft_move_vert(data, keycode);
	if (keycode == 0 || keycode == 2)
		ft_move_hori(data, keycode);
	if (keycode == 123 || keycode == 124)
		ft_rotate(data, keycode);
	raycast(data);
	return (0);
}