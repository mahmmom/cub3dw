/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:57:37 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/09 17:16:56 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	save_map_to_struct(t_data *data, char **temp_map)
{
	int	len;
	int	i;

	len = array_size(temp_map);
	data->map.map_data = (char **)malloc(sizeof(char *) * (len + 1));
	if (!data->map.map_data)
		return ;
	i = -1;
	while (temp_map[++i])
		data->map.map_data[i] = ft_strdup(temp_map[i]);
	data->map.map_data[i] = NULL;
}

int	player_char(char p)
{
	if (p == 'N' || p == 'S' || p == 'W' || p == 'E')
		return (0);
	return (1);
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map_data[++i])
	{
		j = -1;
		while (data->map.map_data[i][++j])
		{
			if (!player_char(data->map.map_data[i][j]))
			{
				data->p.pos_x = j;
				data->p.pos_y = i;
				data->p.dir = data->map.map_data[i][j];
				data->map.map_data[i][j] = '0';
			}
		}
	}
}

void	save_map_info_to_struct(t_data *data)
{
	data->map.height = array_size(data->map.map_data);
	data->map.width = array_width(data->map.map_data);
	player_position(data);
}

void	map_to_struct(t_data *data, char **temp_map)
{
	save_map_to_struct(data, temp_map);
	save_map_info_to_struct(data);
	init_player_direction(data);
}
