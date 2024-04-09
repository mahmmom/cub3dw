/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:52:57 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/08 22:17:08 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		return (error_exit(MLX_IMG_ERR), clean_exit_error(data));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bpp,
			&image->line_len, &image->endian);
	return ;
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size,
			&data->texinfo.size);
	if (image->img == NULL)
		return (error_exit(MLX_IMG_ERR), clean_exit_error(data));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bpp,
			&image->line_len, &image->endian);
	return ;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_exit(MLX_START_ERR), clean_exit_error(data));
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!data->win)
		return (error_exit(MLX_WIN_ERR), clean_exit_error(data));
	return ;
}
