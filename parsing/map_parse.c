/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:03:38 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/27 22:47:25 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

char	**fd_to_tmp_map(char *line, int fd)
{
	int		i;
	char	**temp_map;

	i = 0;
	temp_map = NULL;
	while (line)
	{
		if (!is_map_char_line(line))
			return (free_array(temp_map), free(line), NULL);
		temp_map = (char **)ft_realloc(temp_map, i * sizeof(char *), (i + 2)
				* sizeof(char *));
		if (temp_map == NULL)
			return (free(line), NULL);
		temp_map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
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
			return (NULL);
		if (!is_empty_line(map[i]))
			temp_map[i] = ft_strdup(map[i]);
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

char	**build_map(int fd)
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
	temp_map = fd_to_tmp_map(line, fd);
	if (!temp_map)
		return (NULL);
	map = remove_map_empty_lines(temp_map);
	if (!map)
		return (free_array(temp_map), NULL);
	free_array(temp_map);
	return (map);
}

int	get_map(t_data *data, int fd)
{
	char	**map;

	map = build_map(fd);
	if (!map)
		return (error_exit(MAP_ERR), MAP_ERR);
	if (final_map(data, map) != CORRECT)
		return (free_array(map), MAP_ERR);
	free_array(map);
	return (CORRECT);
}
