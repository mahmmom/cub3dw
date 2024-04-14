/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:50:22 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/13 19:33:42 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_press(t_data *data)
{
	clean_exit(data);
	return (0);
}

static int	key_press_handler(int key, t_data *data)
{
	if (key == ESC_KEY)
		clean_exit(data);
	if (key == LEFT_KEY)
		data->p.rotate -= 1;
	if (key == RIGHT_KEY)
		data->p.rotate += 1;
	if (key == W_KEY)
		data->p.move_y = 1;
	if (key == A_KEY)
		data->p.move_x = -1;
	if (key == S_KEY)
		data->p.move_y = -1;
	if (key == D_KEY)
		data->p.move_x = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == ESC_KEY)
		clean_exit(data);
	if (key == W_KEY && data->p.move_y == 1)
		data->p.move_y = 0;
	if (key == S_KEY && data->p.move_y == -1)
		data->p.move_y = 0;
	if (key == A_KEY && data->p.move_x == -1)
		data->p.move_x += 1;
	if (key == D_KEY && data->p.move_x == 1)
		data->p.move_x -= 1;
	if (key == LEFT_KEY && data->p.rotate <= 1)
		data->p.rotate = 0;
	if (key == RIGHT_KEY && data->p.rotate >= -1)
		data->p.rotate = 0;
	return (0);
}

void	listen_for_input(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, close_press, data);
	mlx_hook(data->win, 2, 1L << 0, key_press_handler, data);
	mlx_hook(data->win, 3, 1L << 1, key_release_handler, data);
}

// // static void	wrap_mouse_position(t_data *data, int x, int y)
// // {
// // 	if (x > data->win_width - DIST_EDGE_MOUSE_WRAP)
// // 	{
// // 		x = DIST_EDGE_MOUSE_WRAP;
// // 		mlx_mouse_move(data->mlx, data->win, x, y);
// // 	}
// // 	if (x < DIST_EDGE_MOUSE_WRAP)
// // 	{
// // 		x = data->win_width - DIST_EDGE_MOUSE_WRAP;
// // 		mlx_mouse_move(data->mlx, data->win, x, y);
// // 	}
// // }

// static int	mouse_motion_handler(int x, int y, t_data *data)
// {
// 	static int	old_x = WIN_WIDTH / 2;

// 	wrap_mouse_position(data, x, y);
// 	if (x == old_x)
// 		return (0);
// 	else if (x < old_x)
// 		data->p.has_moved += rotate_p(data, -1);
// 	else if (x > old_x)
// 		data->p.has_moved += rotate_p(data, 1);
// 	old_x = x;
// 	return (0);
// }
