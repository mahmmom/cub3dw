
#include "../cub3d.h"


void set_text(t_data *data)
{
    data->ptr[0] = mlx_xpm_file_to_image(data->mlx, data->no_path,
                                          &data->img.img_width[0], &data->img.img_height[0]);
    data->texture[0] = (int *)mlx_get_data_addr(data->ptr[0],
                                                 &data->img.bpp[0], &data->img.line_len[0], &data->img.endian[0]);

    data->ptr[1] = mlx_xpm_file_to_image(data->mlx, data->so_path,
                                          &data->img.img_width[1], &data->img.img_height[1]);
    data->texture[1] = (int *)mlx_get_data_addr(data->ptr[1],
                                                 &data->img.bpp[1], &data->img.line_len[1], &data->img.endian[1]);

    data->ptr[2] = mlx_xpm_file_to_image(data->mlx, data->we_path,
                                          &data->img.img_width[2], &data->img.img_height[2]);
    data->texture[2] = (int *)mlx_get_data_addr(data->ptr[2],
                                                 &data->img.bpp[2], &data->img.line_len[2], &data->img.endian[2]);

    data->ptr[3] = mlx_xpm_file_to_image(data->mlx, data->ea_path,
                                          &data->img.img_width[3], &data->img.img_height[3]);
    data->texture[3] = (int *)mlx_get_data_addr(data->ptr[3],
                                                 &data->img.bpp[3], &data->img.line_len[3], &data->img.endian[3]);
}
void    set_player_dir(t_data *data, int j, int k)
{
    (void)j;
    (void)k;
    if (data->map.map_data[data->map.mapy][data->map.mapx] == 'N')
    {
        data->dirx = 1;
        data->planey = -0.66;
    }
    else if (data->map.map_data[data->map.mapy][data->map.mapx] == 'W')
    {
        data->diry = 1;
        data->planex = 0.66;
    }
    else if (data->map.map_data[data->map.mapy][data->map.mapx] == 'E')
    {
        data->diry = -1;
        data->planex = -0.66;
    }
    else
    {
        data->dirx = -1;
        data->planey = 0.66;
    }
}