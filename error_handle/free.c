/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:41:15 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/13 21:11:20 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

void	free_array_void(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void free_str(t_data *data)
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
	if (data->texinfo.north)
		free(data->texinfo.north);
	if (data->texinfo.north)
		free(data->texinfo.north);
	if (data->texinfo.south)
		free(data->texinfo.south);
	if (data->texinfo.west)
		free(data->texinfo.west);
	if (data->texinfo.east)
		free(data->texinfo.east);
	if (data->texinfo.floor)
		free(data->texinfo.floor);
	if (data->texinfo.ceiling)
		free(data->texinfo.ceiling);
}

void	clean_exit(t_data *data)
{
	free_str(data);
	if (data->texture_pixels)
		free_array_void((void**)data->texture_pixels);
	if (data->textures)
		free_array_void((void**)data->textures);
	exit(EXIT_SUCCESS);
}
