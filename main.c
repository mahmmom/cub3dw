/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:28:18 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/27 21:11:11 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->comp.no = NULL;
	data->comp.so = NULL;
	data->comp.we = NULL;
	data->comp.es = NULL;
	data->map.map_data = NULL;
	data->comp.floor = -1;
	data->comp.ceiling = -1;
	data->map.height = 0;
	data->map.width = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->map.p_dir = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		error_exit(ARG_ERR);
		exit(EXIT_FAILURE);
	}
	init_data(&data);
	if (parse_map(&data, av[1]) != CORRECT)
		clean_exit_error(&data);
	clean_exit(&data);
}
