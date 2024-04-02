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
	data->map.mapx = 0;
	data->map.mapy = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->map.p_dir = 0;
}
int	move_mouse(int x, int y, t_data *data)
{
	double	angle_r;

	(void)y;
	angle_r = -(x - WIDTH / 2) / 1200.0;
	ft_rotate(data, angle_r); // Call ft_rotate with data and angle_r
	mlx_mouse_move(data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
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
	mlx_set(&data);
	raycast(&data);
	mlx_loop(data.mlx);
	mlx_hook(data.win, 2, 1L << 0, cub_key_press, &data);
	mlx_hook(data.win, 6, 1L << 6, move_mouse, &data);
	clean_exit(&data);
}
