/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:50:18 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/27 17:17:35 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	all_comp_found(t_data *data)
{
	if (data->comp.no && data->comp.so && data->comp.es && data->comp.we
		&& data->comp.ceiling != -1 && data->comp.floor != -1)
		return (1);
	return (0);
}

int	array_width(char **arry)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (arry[i])
	{
		if (ft_strlen(arry[i]) > len)
			len = ft_strlen(arry[i]);
		i++;
	}
	return (len);
}

void	print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("Array = [%s]\n", str[i]);
		i++;
	}
}

void	print_map_comp(t_data *data)
{
	printf("North = [%s]\n", data->comp.no);
	printf("South = [%s]\n", data->comp.so);
	printf("East = [%s]\n", data->comp.es);
	printf("West = [%s]\n", data->comp.we);
	printf("Ceiling Color = [%d]\n", data->comp.ceiling);
	printf("Floor Color = [%d]\n", data->comp.floor);
	print_array(data->map.map_data);
	printf("Player x = [%d]\n", data->map.p_x);
	printf("Player y = [%d]\n", data->map.p_y);
	printf("Player dir = [%d]\n", data->map.p_dir);
}
