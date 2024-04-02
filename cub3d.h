/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:28:23 by wahmed          #+#    #+#             */
/*   Updated: 2024/03/27 20:17:46 by wahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define W_WIDTH 640
# define W_HEIGHT 640
# define RES 640
# define TILE_SIZE 64
# define TEXTURE_SIZE 64
# define MOVE_SPEED 40
# define ROTATE_SPEED 0.2
# define HORIZONTAL 0
# define VERTICAL 1
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed
# define NUM_RAYS 120

# define ESC_KEY 53
# define D_KEY 124
# define A_KEY 123
# define W_KEY 126
# define S_KEY 125
# define R_KEY 44
# define MOUSE_UP 5
# define MOUSE_DOWN 4

# define E_ARG "Please Enter: <./cub3d> <maps/*.cub>"
# define E_EMPTY "Map is empty"
# define E_MAP_EXT "Invalid Map file extension\nPlease Enter: *.cub"
# define E_MAP "Invalid Map"
# define E_MAP_CHAR "Invalid Map Element"
# define E_TEXT "Invalid Texture input"
# define E_TEXT_PATH "Texture Path doesn't exist"
# define E_COLOR "Enter F/C <R>,<G>,<B>\nvalue should be >= 0 && <= 255"
# define E_INPUT "Invalid Input"
# define E_MALLOC "Malloc Fail"
# define E_D_OPEN "Argument can't be a directory"
# define E_F_OPEN "Cant open file"
# define E_INVALID "Invalid Error type"
# define E_DUPLICATE "Duplicate Map Element"
# define E_WALLS "Map Walls are not closed"
# define E_D_PLAYER "1 player only"
# define E_MAP_SPACE "Invalid map space"

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
	C_ERR,
	MALLOC_ERR,
	OPEN_D_ERR,
	OPEN_F_ERR,
	DUP_ERR,
	WALLS_ERR,
	D_PLAYER_ERR,
	MAP_SPACE_ERR,
}			t_error;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_p
{
	double				x;
	double				y;
	double				plane_x;
	double				plane_y;
	double				dx;
	double				dy;
	double				fov;
}						t_p;

typedef struct s_ray
{
	double				x;
	double				y;
	double				len;
	int					hit;
}						t_ray;

typedef struct s_map
{
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	char	p_dir;
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
	t_img	img;
	t_p		p;
	t_ray	r;
	void	*mlx;
	void	*win;
	double	shift_x;
	double	shift_y;
}			t_data;

// Parsing
int			validate_map(t_data *data, char *file_name);
int			check_map_ext(char *input);
int			parse_map(t_data *data, char *file_name);
void		remove_newline(char **str);
int			all_comp_found(t_data *data);
void		comp_error(t_data *data);

// Texture Parse
int			check_texture(t_data *data, char **array);
int			texture_path(char *path);
int			array_size(char **str);
int			array_width(char **arry);
int			comp_exist(char **array, char *str);

// Map Parse
int			get_map(t_data *data, int fd);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char		**build_map(int fd);
char		**parse_new_map(char **map);
int			is_map_char(char **line);
int			is_map_char_line(char *line);
int			is_empty_line(char *line);
int			check_middle_lines(char **map);
int			final_map(t_data *data, char **map);
void		map_to_struct(t_data *data, char **temp_map);

// Color Parse
int			check_color(t_data *data, char **array);
int			count_commas(char *str);
char		*join_args(char **str);

// Initialize
t_data		*init_args(void);

//MLX
void    mlx_set(t_data *data);
void	data_set(t_data *data);
void	render_scene(t_data *data);

// Render
void	game_start(t_data *data);
void    game_render(int x, int y, t_data *data);

// Hooks
int	close_press(t_data *data);
int	key_press(int keycode, t_data *data);


// Error handler
void		error_exit(enum e_error value);
void		clean_exit_error(t_data *data);
void		print_error(char *msg);

// Free
void		clean_exit(t_data *data);
void		free_array(char **str);
void		free_ptr(void **ptr);

// Print Array
void		print_array(char **str);
void		print_map_comp(t_data *data);

#endif