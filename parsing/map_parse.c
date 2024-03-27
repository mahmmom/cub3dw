/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:03:38 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/27 16:57:32 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map(t_data *data, int fd)
{
	char	**temp_map;

	temp_map = re_build_map(fd);
	if (!temp_map)
		return (error_exit(MAP_ERR), MAP_ERR);
	if (final_2dmap(data, temp_map) != CORRECT)
		return (free_array(temp_map), MAP_ERR);
	free_array(temp_map);
	return (CORRECT);
}
