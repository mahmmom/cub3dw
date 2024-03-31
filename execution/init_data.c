/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:30:44 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/27 17:22:11 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	malloc_error(void)
{
	perror("Error in malloc allocation");
	exit(EXIT_FAILURE);
}

void	data_set(t_data *data)
{
	//Player init
	data->p.x = 0;
	data->p.y = 0;
	data->p.dx = 0;
	data->p.dy = 0;
	data->p.fov = 0;
	data->p.angle = 0;
	//Ray init
	data->r.x = 0;
	data->r.y = 0;
	data->r.len = 0;
	data->r.hit = 0;
	data->r.angle = 0;
	//Movement
	data->shift_x = 0;
	data->shift_y = 0;
}

static void	key_hook(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, close_press, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	//mlx_hook(data->win, 4, 1L << 2, mouse_press, data);
	//mlx_hook(data->win, 6, 1L << 6, julia_track, data);
}

void    mlx_set(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (malloc_error());
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!data->win)
		return (free(data->win), malloc_error());
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->win);
		malloc_error();
	}
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bpp, &data->img.line_len,
			&data->img.endian);
	key_hook(data);
	data_set(data);
}
