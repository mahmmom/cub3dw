/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:49:19 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/14 20:54:42 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	is_valid_pos_wall_collision(t_data *data, double x, double y)
{
	if (data->map.map_data[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map.height - 0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_wall_collision(data, x, y) && is_valid_pos_in_map(data, x,
			y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, new_y))
	{
		data->p.pos_x = new_x;
		data->p.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
