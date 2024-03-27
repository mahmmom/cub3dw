/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:54:54 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/27 17:21:47 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != '\r' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_char(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] != '1' && line[i][j] != '0' && line[i][j] != 'N'
				&& line[i][j] != 'S' && line[i][j] != 'E' && line[i][j] != 'W'
				&& line[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_char_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*join_args(char **str)
{
	int		i;
	char	*color;
	char	*temp;

	if (!str || !*str)
		return (NULL);
	i = 0;
	color = ft_strdup("");
	while (str[i])
	{
		temp = ft_strjoin(color, str[i]);
		free(color);
		color = temp;
		i++;
	}
	return (color);
}
