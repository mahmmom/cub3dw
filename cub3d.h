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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*========================== Defines ==========================*/
// Colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define SKY_BLUE 0x87CEEB

// Screen
# define W_WIDTH 800
# define W_HEIGHT 800
# define TEX_SIZE 64
# define MOVESPEED 0.0625
# define ROTSPEED 0.015

// Buttons
# define ESC_KEY 53
# define D_KEY 2
# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
# define LEFT_KEY 123
# define RIGHT_KEY 124

// Errors
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
# define E_MLX_IMG "mlx image failed"

/*========================== Structs ==========================*/
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
	MLX_START_ERR,
	MLX_WIN_ERR,
	MLX_IMG_ERR,
}			t_error;

enum		e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_tex
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor;
	int		*ceiling;
	int		size;
	int		index;
	double	step;
	double	pos;
	int		x;
	int		y;
}			t_tex;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}			t_p;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

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
	t_img	img;
	t_p		p;
	t_ray	r;
	t_tex	texinfo;
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	int		**texture_pixels;
	int		**textures;
}			t_data;

/*========================== Functions ==========================*/
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
void		init_img_clean(t_img *img);
void		init_mlx(t_data *data);
void		init_texture_img(t_data *data, t_img *image, char *path);
void		init_texinfo(t_tex *textures);
void		init_img(t_data *data, t_img *image, int width, int height);
void		init_ray(t_ray *ray);
void		init_texture_pixels(t_data *data);
void		init_textures(t_data *data);
void		init_player_direction(t_data *data);
void		init_data(t_data *data);

// MLX
void		mlx_set(t_data *data);
void		data_set(t_data *data);
void		render_scene(t_data *data);

// Render
int			game_start(t_data *data);
void		game_render(int x, int y, t_data *data);
void		update_texture_pixels(t_data *data, t_tex *tex, t_ray *ray, int x);
int			raycasting(t_p *player, t_data *data);
void		render_raycast(t_data *data);
int			render(t_data *data);

// Movement
int			validate_move(t_data *data, double new_x, double new_y);
int			rotate_player(t_data *data, double rotdir);
int			move_player(t_data *data);

// Hooks
int			close_press(t_data *data);
int			key_press(int keycode, t_data *data);
void		listen_for_input(t_data *data);

// Error handler
void		error_exit(enum e_error value);
void		clean_exit_error(t_data *data);
void		print_error(char *msg);

// Free
void		clean_exit(t_data *data);
void		free_array(char **str);
void		free_ptr(void **ptr);
void		free_array_void(void **tab);
void		free_str(t_data *data);

// Print Array
void		print_array(char **str);
void		print_map_comp(t_data *data);

#endif