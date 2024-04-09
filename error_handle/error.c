/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:26:36 by wahmed          #+#    #+#             */
/*   Updated: 2024/03/20 16:13:43 by wahmed        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
}

void	print_error1(enum e_error value)
{
	if (value == ARG_ERR)
		return (print_error(E_ARG));
	else if (value == EMPTY_ERR)
		return (print_error(E_EMPTY));
	else if (value == MAP_EXT_ERR)
		return (print_error(E_MAP_EXT));
	else if (value == MAP_ERR)
		return (print_error(E_MAP));
	else if (value == MAP_CHAR_ERR)
		return (print_error(E_MAP_CHAR));
	else if (value == TEXT_ERR)
		return (print_error(E_TEXT));
	else if (value == TEXT_PATH_ERR)
		return (print_error(E_TEXT_PATH));
	else if (value == C_ERR)
		return (print_error(E_COLOR));
	else if (value == MALLOC_ERR)
		return (print_error(E_MALLOC));
}

void	print_error2(enum e_error value)
{
	if (value == OPEN_D_ERR)
		return (print_error(E_D_OPEN));
	else if (value == OPEN_F_ERR)
		return (print_error(E_F_OPEN));
	else if (value == DUP_ERR)
		return (print_error(E_DUPLICATE));
	else if (value == WALLS_ERR)
		return (print_error(E_WALLS));
	else if (value == D_PLAYER_ERR)
		return (print_error(E_D_PLAYER));
	else if (value == MAP_SPACE_ERR)
		return (print_error(E_MAP_SPACE));
	else if (value == MLX_IMG_ERR)
		return (print_error(E_MLX_IMG));
}

void	error_exit(enum e_error value)
{
	if (value < 10)
		print_error1(value);
	else
		print_error2(value);
}

void	clean_exit_error(t_data *data)
{
	if (data->comp.no)
		free(data->comp.no);
	if (data->comp.so)
		free(data->comp.so);
	if (data->comp.we)
		free(data->comp.we);
	if (data->comp.es)
		free(data->comp.es);
	if (data->map.map_data)
		free_array(data->map.map_data);
	exit(EXIT_FAILURE);
}
