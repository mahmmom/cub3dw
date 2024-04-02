#include "../cub3d.h"

void	get_line_dist(t_data *data, t_ray *rayc, int x)
{
	if (rayc->side == 0)
		rayc->perpwalldist = (rayc->sidedistx - rayc->deltadistx);
	else
		rayc->perpwalldist = (rayc->sidedisty - rayc->deltadisty);
	init_line(data, rayc);
	while (rayc->y < HEIGHT)
	{
		if (rayc->y >= data->line_start && rayc->y <= data->line_end)
		{
			rayc->texy = (int)rayc->texpos & (data->img.img_height[0] - 1);
			rayc->texpos += rayc->step;
			data->buffer[rayc->y][x] = ret_color(data, rayc);
		}
		rayc->y++;
	}
}
void	ft_dda(t_ray *rayc, t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rayc->sidedistx < rayc->sidedisty)
		{
			rayc->sidedistx += rayc->deltadistx;
			data->map.mapx += rayc->stepx;
			rayc->side = 0;
		}
		else
		{
			rayc->sidedisty += rayc->deltadisty;
			data->map.mapy += rayc->stepy;
			rayc->side = 1;
		}
		if (data->map.map_data[data->map.mapy][data->map.mapx] == '1')
			hit = 1;
	}
}

void	get_side_dist(t_data *data, t_ray *rayc)
{
	if (data->raydiry < 0)
	{
		rayc->stepy = -1;
		rayc->sidedisty = (data->posy - data->map.mapy) * rayc->deltadisty;
	}
	else
	{
		rayc->stepy = 1;
		rayc->sidedisty = (data->map.mapy + 1.0 - data->posy) * rayc->deltadisty;
	}
	if (data->raydirx < 0)
	{
		rayc->stepx = -1;
		rayc->sidedistx = (data->posx - data->map.mapx) * rayc->deltadistx;
	}
	else
	{
		rayc->stepx = 1;
		rayc->sidedistx = (data->map.mapx + 1.0 - data->posx) * rayc->deltadistx;
	}
}