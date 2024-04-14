/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:47:07 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/14 21:52:00 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->p.pos_x + (data->p.dir_x * MOVESPEED);
	new_y = data->p.pos_y + (data->p.dir_y * MOVESPEED);
	return (validate_move(data, new_x, new_y));
}

static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->p.pos_x - data->p.dir_x * MOVESPEED;
	new_y = data->p.pos_y - data->p.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->p.pos_x + data->p.dir_y * MOVESPEED;
	new_y = data->p.pos_y - data->p.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->p.pos_x - data->p.dir_y * MOVESPEED;
	new_y = data->p.pos_y + data->p.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->p.move_y == 1)
		moved += move_player_forward(data);
	if (data->p.move_y == -1)
		moved += move_player_backward(data);
	if (data->p.move_x == -1)
		moved += move_player_left(data);
	if (data->p.move_x == 1)
		moved += move_player_right(data);
	if (data->p.rotate != 0)
		moved += rotate_player(data, data->p.rotate);
	return (moved);
}
