/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:03:38 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/21 19:46:46 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_to_struct(t_data *data, char **temp_map)
{
	int len;
	int	i;
	
	len = array_size(temp_map);
	data->map.map_data = (char **)malloc(sizeof(char *) * (len + 1));
	if(!data->map.map_data)
		return ;
	i = -1;
	while (temp_map[++i])
		data->map.map_data[i] = ft_strdup(temp_map[i]);
	data->map.map_data[i] = NULL;
}

int	get_map(t_data *data, int fd)
{
	char	**temp_map;

	(void)data;
	temp_map = re_build_map(fd);
	if (!temp_map)
		return (error_exit(MAP_ERR), MAP_ERR);
	if (is_map_char(temp_map) == 0)
		return (free_array(temp_map), error_exit(MAP_ERR), MAP_ERR);
	print_array(temp_map);
	// we do this step at the end
	//map_to_struct(data, temp_map);
	//free_array(temp_map);
	// if (final_2dmap(data) == 0)
	// 	return (error_exit(MAP_ERR), MAP_ERR);
	return (CORRECT);
}
