/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:50:24 by mohamoha          #+#    #+#             */
/*   Updated: 2024/04/09 17:50:55 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_args(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi_rgb(char *str)
{
	long	sign;
	long	result;
	long	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if ((result > 255 / 10) || (result == 255 / 10 && (str[i] - '0') > 255
				% 10))
		{
			if (sign == 1)
				return ((long long)INT_MAX + 1);
			return ((long long)INT_MAX + 1);
		}
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	convert_to_integer(char **components)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi_rgb(components[0]);
	green = ft_atoi_rgb(components[1]);
	blue = ft_atoi_rgb(components[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		return (-2);
	return ((red << 16) | (green << 8) | blue);
}

char	*parse_color_line(char **array)
{
	char	*color;
	char	*trim;
	char	**temp;

	if (!array || !*array)
		return (NULL);
	color = join_args(array + 1);
	trim = ft_strtrim(color, " \t\v\f\r\n");
	free(color);
	temp = ft_split(trim, ' ');
	free(trim);
	color = join_args(temp);
	free_array(temp);
	return (color);
}

int	check_color(t_data *data, char **array)
{
	char	**temp;
	char	*trim;

	if (array_size(array) != 2)
		return (free_array(array), error_exit(C_ERR), C_ERR);
	trim = parse_color_line(array);
	if (count_commas(trim) != 2)
		return (free(trim), free_array(array), error_exit(C_ERR), C_ERR);
	temp = ft_split(trim, ',');
	free(trim);
	if (!temp)
		return (free_array(array), error_exit(C_ERR), C_ERR);
	if (check_args(temp) == 0)
		return (free_array(array), free_array(temp), error_exit(C_ERR), C_ERR);
	if (data->comp.ceiling == -1 && ft_strncmp(array[0], "C", 1) == 0)
		data->comp.ceiling = convert_to_integer(temp);
	else if (data->comp.floor == -1 && ft_strncmp(array[0], "F", 1) == 0)
		data->comp.floor = convert_to_integer(temp);
	else
		return (free_array(temp), free_array(array), error_exit(DUP_ERR),
			DUP_ERR);
	if (data->comp.ceiling == -2 || data->comp.floor == -2)
		return (free_array(temp), free_array(array), error_exit(C_ERR), C_ERR);
	return (free_array(temp), free_array(array), CORRECT);
}
