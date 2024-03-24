/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:28:23 by mohamoha          #+#    #+#             */
/*   Updated: 2024/03/21 14:47:01 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h" // MLX library
// # include <GLUT/GLUT.h>
// # include <GLUT/glut.h>
// # include <OpenGL/OpenGL.h>
// # include <OpenGL/gl.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PI 3.1415926535
# define PI2 PI / 2
# define PI3 3 * PI / 2
# define DR 0.0174533 // 1 Degree to RAD
# define EPSILON 0.0001

# define E_ARG "Please Enter: <./cub3d> <maps/*.cub>"
# define E_MAP_EXT "Invalid Map file extension\nPlease Enter: *.cub"
# define E_MAP "Invalid Map"
# define E_EMPTY "Map is empty"
# define E_TEXT "Invalid Texture input"
# define E_TEXT_PATH "Texture Path doesn't exist"
# define E_COLOR "Invalid Color Enter <Red>,<Green>,<Blue>\nvalue should be 0 <= color <= 255"
# define E_INPUT "Invalid Input"
# define E_MALLOC "Malloc Fail"
# define E_OPEN "Cant open file"
# define E_INVALID "Invalid Error type"
# define E_DUPLICATE "Duplicate Map Element"
# define E_WALLS "Map Walls are not closed"
# define E_D_PLAYER "1 player only"

typedef enum e_error
{
	CORRECT,
	ARG_ERR,
	EMPTY_ERR,
	MAP_EXT_ERR,
	MAP_ERR,
	MAP_CHAR_ERR,
	TEXT_ERR,
	TEXT_PATH_ERR,
	COLOR_ERR,
	MALLOC_ERR,
	OPEN_ERR,
	DUP_ERR,
	WALLS_ERR,
	D_PLAYER_ERR,
}			t_error;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map_data;
}			t_map;

typedef struct s_comp
{
	char	*no;
	char	*so;
	char	*we;
	char	*es;
	int		floor;
	int		ceiling;
}			t_comp;

typedef struct s_data
{
	t_map	map;
	t_comp	comp;
}			t_data;

// Parsing
int			validate_map(t_data *data, char *file_name);
int			check_map_ext(char *input);
int			parse_map(t_data *data, char *file_name);
void		remove_newline(char **str);
int			all_comp_found(t_data *data);
void		comp_error(t_data *data);

// Texture
int			check_texture(t_data *data, char **array);
int			texture_path(char *path);
int			array_size(char **str);
int			array_width(char **arry);
int			comp_exist(char **array, char *str);

// Map
int			get_map(t_data *data, int fd);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char		**re_build_map(int fd);
char		**parse_new_map(char **map);
int			is_map_char(char **line);
int			is_empty_line(char *line);
int			final_2dmap(char **map);


// Colors
int			check_color(t_data *data, char **array);
int			count_commas(char *str);

// Initialize
t_data		*init_args(void);

// Error handler
void		error_exit(enum e_error value);
void		print_error(char *msg);

// Free
void		clean_exit(t_data *data);
void		free_array(char **str);
void		free_ptr(void **ptr);

// Print Array
void		print_array(char **str);

#endif