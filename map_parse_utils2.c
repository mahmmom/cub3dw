/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:29:04 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/21 19:48:08 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	walls_up_down(char **map)
// {
// 	return (1);
// }


















int	final_2dmap(t_data *data)
{
	//print_array(data->map.map_data);
	data->map.height = array_size(data->map.map_data);
	data->map.width = array_width(data->map.map_data);
	//walls_up_down(data);
	return (1);
}
