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

int	walls_checker(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		if ((map[i][0] != '1' && map[i][0] != ' ')
			|| (map[i][ft_strlen(map[i])] != '1'
			&& map[i][ft_strlen(map[i])] != ' '))
			return(0);
	i = -1;
	while (++i < ft_strlen(map[0]))
		if (map[0][i] != '1' && map[0][i] != ' ')
			return(0);
	i = -1;
	while (++i < ft_strlen(map[array_size(map) - 1]))
		if (map[array_size(map)][i] != '1'
		&& map[array_size(map)][i] != ' ')
			return(0);
	return(1);
}


int	final_2dmap(char **map)
{
	if(!walls_checker(map))
		return (error_exit(WALLS_ERR), WALLS_ERR);

	return (CORRECT);
}
