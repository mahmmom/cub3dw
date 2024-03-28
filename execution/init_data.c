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

static void	data_init(t_data *data)
{
    
}

void    start_mlx(t_data *data)
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
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	// key_hook(data);
	// data_init(data);
}
