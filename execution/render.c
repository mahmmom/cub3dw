/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:44:55 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/14 21:10:32 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = y * (img->line_len / 4) + x;
	img->addr[pixel] = color;
}

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		my_pixel_put(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		my_pixel_put(image, x, y, data->comp.ceiling);
	else if (y < data->win_height -1)
		my_pixel_put(image, x, y, data->comp.floor);
}

static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

void	render_raycast(t_data *data)
{
	init_texture_pixels(data);
	init_ray(&data->r);
	raycasting(&data->p, data);
	render_frame(data);
}

int	render(t_data *data)
{
	data->p.has_moved += move_player(data);
	if (data->p.has_moved == 0)
		return (0);
	render_raycast(data);
	return (0);
}
