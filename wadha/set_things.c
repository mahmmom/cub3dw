#include "../cub3d.h"


void set_things(t_data *data)
{
data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->move_speed = 0.15;
	data->rotate = 0.15;
}
void	init_rayc(t_ray *rayc)
{
	rayc->sidedistx = 0;
	rayc->sidedisty = 0;
	rayc->deltadistx = 0;
	rayc->deltadisty = 0;
	rayc->perpwalldist = 0;
	rayc->stepx = 0;
	rayc->stepy = 0;
	rayc->wallx = 0;
	rayc->side = 0;
	rayc->y = 0;
	rayc->texx = 0;
	rayc->texy = 0;
	rayc->texpos = 0;
	rayc->step = 0;
}
void	init_var(t_data *data, t_ray *rayc, int x)
{
	double	camerax;

	camerax = 2 * x / (double)(WIDTH) - 1;
	data->raydirx = data->dirx + data->planex * camerax;
	data->raydiry = data->diry + data->planey * camerax;
	data->map.mapx = (int)(data->posx);
	data->map.mapy = (int)(data->posy);
	rayc->deltadistx = fabs(1 / data->raydirx);
	rayc->deltadisty = fabs(1 / data->raydiry);
}


int	raycast(t_data *data)
{
	int		x;
	t_ray	rayc;

	x = 0;
	while (x < WIDTH)
	{
		init_rayc(&rayc);
		init_var(data, &rayc, x);
		get_side_dist(data, &rayc);
		ft_dda(&rayc, data);
		get_line_dist(data, &rayc, x);
		draw_line(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}