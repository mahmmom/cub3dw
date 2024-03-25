#include "cub3d.h"


int all_comp_found(t_data *data)
{
    if (data->comp.no && data->comp.so && data->comp.es
        && data->comp.we && data->comp.ceiling != -1 && data->comp.floor != -1)
            return (1);
    return (0);
}

void    comp_error(t_data *data)
{
    if (!data->comp.no || !data->comp.so || !data->comp.es
        || !data->comp.we)
    {
        printf("Error\n");
        printf("Missing Texture\n");
    }
    else if (!data->comp.ceiling || !data->comp.floor)
    {
        printf("Error\n");
        printf("Missing Color\n");
    }
}

int	array_width(char **arry)
{
	int	i;
	size_t	len;

	len = 0;
	i = 0;
	while (arry[i])
	{
		if (ft_strlen(arry[i]) > len)
			len = ft_strlen(arry[i]);
		i++;
	}
	return (len);
}

void    print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("Array = [%s]\n", str[i]);
		i++;
	}
}
