/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:41:15 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/25 21:42:00 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if(!str || !*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

void	clean_exit(t_data *data)
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
	exit(EXIT_SUCCESS);
}
