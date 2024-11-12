/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:55:00 by dberreby          #+#    #+#             */
/*   Updated: 2023/12/20 16:34:56 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	malloc_var(t_vars *vars)
{
	vars->north_wall = malloc(sizeof(t_img));
	if (!vars->north_wall)
		return (0);
	vars->south_wall = malloc(sizeof(t_img));
	if (!vars->south_wall)
		return (0);
	vars->east_wall = malloc(sizeof(t_img));
	if (!vars->east_wall)
		return (0);
	vars->west_wall = malloc(sizeof(t_img));
	if (!vars->west_wall)
		return (0);
	vars->data = malloc(sizeof(t_data));
	if (!vars->data)
		return (0);
	vars->ray = malloc(sizeof(t_ray));
	if (!vars->ray)
		return (0);
	vars->floor = ft_calloc(4, sizeof(int));
	if (!vars->floor)
		return (0);
	vars->roof = ft_calloc(4, sizeof(int));
	if (!vars->roof)
		return (0);
	return (1);
}

int	set_var_null(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->size_line = NULL;
	vars->pi = M_PI;
	vars->floor = NULL;
	vars->roof = NULL;
	vars->north_wall = NULL;
	vars->south_wall = NULL;
	vars->east_wall = NULL;
	vars->west_wall = NULL;
	vars->image = NULL;
	vars->data = NULL;
	vars->ray = NULL;
	return (malloc_var(vars));
}

// int	set_var_null(t_vars *vars)
// {
// 	vars->mlx = NULL;
// 	vars->win = NULL;
// 	vars->map = NULL;
// 	vars->size_line = NULL;
// 	vars->pi = M_PI;
// 	vars->floor = NULL;
// 	vars->roof = NULL;
// 	vars->north_wall = NULL;
// 	vars->south_wall = NULL;
// 	vars->east_wall = NULL;
// 	vars->west_wall = NULL;
// 	vars->image = NULL;
// 	// vars->image = malloc(sizeof(t_img));
// 	// if (!vars->image)
// 	// 	return (0);
// 	// vars->image->img = NULL;
// 	vars->north_wall = malloc(sizeof(t_img));
// 	if (!vars->north_wall)
// 		return (0);
// 	vars->south_wall = malloc(sizeof(t_img));
// 	if (!vars->south_wall)
// 		return (0);
// 	vars->east_wall = malloc(sizeof(t_img));
// 	if (!vars->east_wall)
// 		return (0);
// 	vars->west_wall = malloc(sizeof(t_img));
// 	if (!vars->west_wall)
// 		return (0);
// 	vars->data = malloc(sizeof(t_data));
// 	if (!vars->data)
// 		return (0);
// 	vars->ray = malloc(sizeof(t_ray));
// 	if (!vars->ray)
// 		return (0);
// 	vars->floor = ft_calloc(4, sizeof(int));
// 	if (!vars->floor)
// 		return (0);
// 	vars->roof = ft_calloc(4, sizeof(int));
// 	if (!vars->roof)
// 		return (0);
// 	return (1);
// }

// int	load_images(t_vars *vars, char *str, char dir, int i)
// {
// 	(void)i;
// 	if (dir == 'N')
// 	{
// 		vars->north_wall->img = mlx_xpm_file_to_image(vars->mlx,
// 				str, &vars->north_wall->tex_width,
// 				&vars->north_wall->tex_height);
// 		if (!vars->north_wall->img)
// 			return (0);
// 	}
// 	else if (dir == 'S')
// 	{
// 		vars->south_wall->img = mlx_xpm_file_to_image(vars->mlx,
// 				str, &vars->south_wall->tex_width,
// 				&vars->south_wall->tex_height);
// 		if (!vars->south_wall->img)
// 			return (0);
// 	}
// 	if (dir == 'E')
// 	{
// 		vars->east_wall->img = mlx_xpm_file_to_image(vars->mlx,
// 				str, &vars->east_wall->tex_width,
// 				&vars->east_wall->tex_height);
// 		if (!vars->east_wall->img)
// 			return (0);
// 	}
// 	if (dir == 'W')
// 	{
// 		vars->west_wall->img = mlx_xpm_file_to_image(vars->mlx,
// 				str, &vars->west_wall->tex_width,
// 				&vars->west_wall->tex_height);
// 		if (!vars->west_wall->img)
// 			return (0);
// 	}
// 	return (1);
// }

void	init_tex(t_vars *vars, char dir)
{
	if (dir == 'N')
		vars->north_wall->addr = mlx_get_data_addr(vars->north_wall->img,
				&vars->north_wall->bpp, &vars->north_wall->rowlen,
				&vars->north_wall->endian);
	else if (dir == 'S')
		vars->south_wall->addr = mlx_get_data_addr(vars->south_wall->img,
				&vars->south_wall->bpp, &vars->south_wall->rowlen,
				&vars->south_wall->endian);
	else if (dir == 'E')
		vars->east_wall->addr = mlx_get_data_addr(vars->east_wall->img,
				&vars->east_wall->bpp, &vars->east_wall->rowlen,
				&vars->east_wall->endian);
	else if (dir == 'W')
		vars->west_wall->addr = mlx_get_data_addr(vars->west_wall->img,
				&vars->west_wall->bpp, &vars->west_wall->rowlen,
				&vars->west_wall->endian);
}

int	extract_image(t_vars *vars, char **file, int i, int k)
{
	int		tmp;
	char	dir;
	char	*str;

	dir = file[i][k];
	k += 2;
	while (file[i][k] && file[i][k] == ' ')
		k++;
	tmp = k;
	while (file[i][k] && file[i][k] != ' ' && file[i][k] != '\n')
		k++;
	str = ft_calloc((k - tmp + 1), sizeof(char));
	if (!str)
		return (0);
	k = tmp;
	if (!get_image_name(file, str, i, k))
		return (free(str), 0);
	if (!load_images(vars, str, dir, i))
		return (free(str), 0);
	init_tex(vars, dir);
	return (free(str), 1);
}

void	put_color_in_struct(t_vars *vars, char c, int color, char *nb)
{
	if (c == 'F')
		vars->floor[color] = atoi(nb);
	else if (c == 'C')
		vars->roof[color] = atoi(nb);
}
