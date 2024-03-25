/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:29:04 by wahmed          #+#    #+#             */
/*   Updated: 2024/03/25 20:39:31 by wahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int walls_checker(char **map)
{
    size_t  i;

    i = -1;
    while (map[++i])
        if ((map[i][0] != '1' && map[i][0] != ' ')
            || (map[i][ft_strlen(map[i]) - 1] != '1'
            && map[i][ft_strlen(map[i]) - 1] != ' '))
            return(0);
    i = -1;
    while (++i < ft_strlen(map[0]))
        if (map[0][i] != '1' && map[0][i] != ' ')
            return(0);
    i = -1;
    while (++i < ft_strlen(map[array_size(map) - 1]))
        if (map[array_size(map) - 1][i] != '1'
        && map[array_size(map) - 1][i] != ' ')
            return(0);
    return(1);
}

int player_double(char **map)
{
    int i;
    int j;
    int flag;

    i = -1;
    flag = 0;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S'
                || map[i][j] == 'E' || map[i][j] == 'W')
                    flag++;
        }
    }
    if (flag != 1)
        return (0);
    return (1);
}

// void	space_checker(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j] == ' ')
// 				j++;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == ' ')
// 				map[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}
// }

int   space_checker(char **map)
{
	int i ;
	int a;
	
	a = -1;
    while (map[++a])
	{
        i = -1;
        while (map[a][++i])
		{
            if (map[a][i] == ' ')
			{
                if (map[a][i + 1] && (map[a][i + 1] != '1'
                    && map[a][i + 1] != ' '))
                    return(0);
                if (i != 0 && map[a][i - 1] && (map[a][i - 1] != '1'
                    && map[a][i - 1] != ' '))
                    return(0);
                if (map[a + 1] && map[a + 1][i]
                    && (map[a + 1][i] != '1' && map[a + 1][i] != ' '))
                    return(0);
                if (a != 0 && map[a - 1] && map[a - 1][i]
                && (map[a - 1][i] != '1' && map[a - 1][i] != ' '))
                    return(0);
			}
		}
    }
	return(1);
}

char    **rect_map(char **map)
{
    int     i;
    char    **tmp;
    int     l;
    int     w;

    i = 0;
    l = array_size(map);
    w = array_width(map);
    tmp = malloc(sizeof(char *) * (l + 1));
    if (!tmp)
        return (NULL);
    while (map[i])
    {
        tmp[i] = malloc(sizeof(char) * (w + 1));
        if (!tmp[i])
            return (NULL);
        ft_memset(tmp[i], ' ', w);
        tmp[i][w] = '\0';
		ft_memcpy(tmp[i], map[i], ft_strlen(map[i]));
        i++;
    }
    tmp[i] = NULL;
    return (tmp);
}

int final_2dmap(char **map)
{
	char **tmp;

	tmp = NULL;
    if(!walls_checker(map))
        return (error_exit(WALLS_ERR), WALLS_ERR);
    if(!player_double(map))
		return (error_exit(D_PLAYER_ERR), D_PLAYER_ERR);
	tmp = rect_map(map);
	free_array(map);
	if(!space_checker(tmp))
		return (free(tmp), error_exit(MAP_SPACE_ERR), MAP_SPACE_ERR);
	free_array(tmp);
    return (CORRECT);
}
