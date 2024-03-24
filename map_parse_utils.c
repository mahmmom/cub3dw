/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:41:27 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/21 21:22:49 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
			&& line[i] != '\r' && line[i] != '\n')
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
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new_ptr, ptr, old_size);
	ft_bzero(new_ptr + old_size, new_size - old_size);
	free(ptr);
	return (new_ptr);
}

char	**function_to_name(char *line, int fd)
{
	int		i;
	char	**temp_map;

	i = 0;
	temp_map = NULL;
	while (line)
	{
		temp_map = (char **)ft_realloc(temp_map, i * sizeof(char *), (i + 2)
				* sizeof(char *));
		if (temp_map == NULL)
			return (free(line), NULL);
		if(!is_map_char_line(line))
			return (free_array(temp_map), free(line), NULL);
		temp_map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

int	check_middle_lines(char **map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		if (flag == 0 && is_empty_line(map[i]))
			flag++;
		if (!is_empty_line(map[i]) && flag != 0)
			return (0);
		i++;
	}
	return (1);
}

char	**remove_map_empty_lines(char **map)
{
	int		i;
	char	**temp_map;

	i = 0;
	temp_map = NULL;
	if (!check_middle_lines(map))
			return (NULL);
	while (map[i])
	{
		temp_map = (char **)ft_realloc(temp_map, i * sizeof(char *), (i + 2)
				* sizeof(char *));
		if (temp_map == NULL)
			return (free(map), NULL);
		if(!is_empty_line(map[i]))
			temp_map[i] = ft_strdup(map[i]);
		free(map[i]);
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

char	**re_build_map(int fd)
{
	char	**temp_map;
	char	**map;
	char	*line;

	temp_map = NULL;
	map = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line && is_empty_line(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	temp_map = function_to_name(line, fd);
	if(!temp_map)
		return (NULL);
	map = remove_map_empty_lines(temp_map);
	//free_array(temp_map);
	if (!map)
		return (NULL);
	return (map);
}
