#include "../cub3d.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	game_render(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	return ;
}

void show_map (t_data *data)
{
	// int i = 0;
	int y = 0;
	while (data->map.map_data[y])
	{
		printf("%s\n", data->map.map_data[y]);
		y++;
	}
}

void game_start(t_data *data)
{
    int x;
    int y;
    int draw_x;
    int draw_y;
    // int player_draw_x;
    // int player_draw_y;
    int i;
    int j;
    void *img_ptr; // Pointer to hold the image data
    void *player_ptr; // Pointer to hold the image data
    int img_width; // Width of the image
    int img_height; // Height of the image

    // Load XPM image file for the player
    img_ptr = mlx_xpm_file_to_image(data->mlx, "bricks.xpm", &img_width, &img_height);
	player_ptr = mlx_xpm_file_to_image(data->mlx, "Crash.xpm", &img_width, &img_height);
    if (!img_ptr)
    {
        // Error handling if image loading fails
        printf("Error: Failed to load image.\n");
        return;
    }

    y = 0;
    //show_map(data);
    j = 0;
    while (y < (data->map.height*TILE_SIZE) && data->map.map_data[j])
    {
        x = 0;
        i = 0;
        while (x < (data->map.width*TILE_SIZE) && data->map.map_data[j][i])
        {
            draw_x = x * TILE_SIZE;
            draw_y = y * TILE_SIZE;
            if (data->map.map_data[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->win, img_ptr, draw_x, draw_y);
            else if (data->map.map_data[j][i] == '0' || data->map.map_data[j][i] == 32)
            {
                // Draw black square for empty space
                mlx_put_image_to_window(data->mlx, data->win, data->img.img, draw_x, draw_y);
            }
            x++;
            i++;
        }
        j++;
        y++;
    }
	//player
	data->map.p_x = data->map.p_x * TILE_SIZE;
	data->map.p_y = data->map.p_y * TILE_SIZE;
	mlx_put_image_to_window(data->mlx, data->win, player_ptr, data->map.p_x, data->map.p_y);

    //mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

// void	drawing(t_data *data)
// {
// 	cast_rays(data);
// 	mlx_put_image_to_window(data->mlx, data->win,
// 		data->img.img, 0, 0);
// 	return ;
// }
