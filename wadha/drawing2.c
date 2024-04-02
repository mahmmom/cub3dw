#include "../cub3d.h"

void	init_line(t_data *cub, t_ray *rayc)
{
	int	lineheight;

	lineheight = (int)(HEIGHT / rayc->perpwalldist);
	cub->line_start = -lineheight / 2 + HEIGHT / 2;
	if (cub->line_start < 0)
		cub->line_start = 0;
	cub->line_end = lineheight / 2 + HEIGHT / 2;
	if (cub->line_end >= HEIGHT)
		cub->line_end = HEIGHT - 1;
	if (cub->line_start >= HEIGHT)
		cub->line_start = 0;
	if (rayc->side == 0)
		rayc->wallx = cub->posy + rayc->perpwalldist * cub->raydiry;
	else
		rayc->wallx = cub->posx + rayc->perpwalldist * cub->raydirx;
	rayc->wallx -= floor((rayc->wallx));
	rayc->texx = (int)(rayc->wallx * (double)(GRID));
	if (rayc->side == 0 && cub->raydirx > 0)
		rayc->texx = GRID - rayc->texx - 1;
	if (rayc->side == 1 && cub->raydiry < 0)
		rayc->texx = GRID - rayc->texx - 1;
	rayc->step = 1.0 * GRID / lineheight;
	rayc->texpos = (cub->line_start - HEIGHT / 2
			+ lineheight / 2) * rayc->step;
	rayc->y = 0;
}

int	ret_color(t_data *data, t_ray *rayc)
{
	int	color;

	color = 0;
	if (rayc->side == 0 && data->raydirx > 0)
		color = (int)data->texture[0][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 0 && data->raydirx < 0)
		color = (int)data->texture[1][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 1 && data->raydiry > 0)
		color = (int)data->texture[2][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 1 && data->raydiry < 0)
		color = (int)data->texture[3][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}




void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_l + x * (data->bp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i < HEIGHT / 2)
			ft_put_pixel(data, x, i, data->f_color);
		else if (i > HEIGHT / 2)
			ft_put_pixel(data, x, i, data->c_color);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		if (i >= data->line_start && i <= data->line_end)
		{
			ft_put_pixel(data, x, i, data->buffer[i][x]);
		}
		i++;
	}
}