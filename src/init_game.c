/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:26 by dberreby          #+#    #+#             */
/*   Updated: 2024/01/08 11:22:09 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_all2(t_vars *vars)
{
	if (vars->image)
	{
		if (vars->image->img)
			mlx_destroy_image(vars->mlx, vars->image->img);
		free(vars->image);
	}
	if (vars->floor)
		free(vars->floor);
	if (vars->roof)
		free(vars->roof);
	if (vars->size_line)
		free(vars->size_line);
	if (vars->data)
		free(vars->data);
	if (vars->ray)
		free(vars->ray);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map)
		free_map(vars->map);
}

void	free_all(t_vars *vars)
{
	if (vars->north_wall)
	{
		if (vars->north_wall->img)
			mlx_destroy_image(vars->mlx, vars->north_wall->img);
		free(vars->north_wall);
	}
	if (vars->south_wall)
	{
		if (vars->south_wall->img)
			mlx_destroy_image(vars->mlx, vars->south_wall->img);
		free(vars->south_wall);
	}
	if (vars->east_wall)
	{
		if (vars->east_wall->img)
			mlx_destroy_image(vars->mlx, vars->east_wall->img);
		free(vars->east_wall);
	}
	if (vars->west_wall)
	{
		if (vars->west_wall->img)
			mlx_destroy_image(vars->mlx, vars->west_wall->img);
		free(vars->west_wall);
	}
	free_all2(vars);
}

int	init_all(t_vars *vars)
{
	vars->rgb_floor = get_rgb(vars->floor);
	vars->rgb_ceiling = get_rgb(vars->roof);
	vars->data->cur_time = 0;
	vars->data->old_time = 0;
	vars->data->texture = 0;
	return (1);
}

int	init_game(t_vars *vars, char *filename)
{
	char	**file;

	vars->win_x = 640;
	vars->win_y = 480;
	if (!set_var_null(vars))
		return (0);
	file = get_map(filename);
	if (!file)
		return (free_all(vars), 0);
	if (!init_mlx(vars))
		return (free_map(file), free_all(vars), 0);
	if (!extract_textures(vars, file))
		return (free_map(file), free_all(vars), 0);
	if (!init_map(vars, file))
		return (free_map(file), free_all(vars), 0);
	if (!init_all(vars))
		return (free_map(file), free_all(vars), 0);
	return (free_map(file), 1);
}

// void	free_all(t_vars *vars)
// {
// 	if (vars->north_wall->img)
// 		mlx_destroy_image(vars->mlx, vars->north_wall->img);
// 	if (vars->south_wall->img)
// 		mlx_destroy_image(vars->mlx, vars->south_wall->img);
// 	if (vars->east_wall->img)
// 		mlx_destroy_image(vars->mlx, vars->east_wall->img);
// 	if (vars->west_wall->img)
// 		mlx_destroy_image(vars->mlx, vars->west_wall->img);
// 	if (vars->floor)
// 		free(vars->floor);
// 	if (vars->roof)
// 		free(vars->roof);
// 	free(vars->north_wall);
// 	free(vars->south_wall);
// 	free(vars->east_wall);
// 	free(vars->west_wall);
// 	if (vars->size_line)
// 		free(vars->size_line);
// 	if (vars->data)
// 		free(vars->data);
// 	if (vars->ray)
// 		free(vars->ray);
// 	if (vars->image->img)
// 		mlx_destroy_image(vars->mlx, vars->image->img);
// 	if (vars->image)
// 		free(vars->image);
// 	if (vars->win)
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	if (vars->mlx)
// 	{
// 		mlx_destroy_display(vars->mlx);
// 		free(vars->mlx);
// 	}
// 	if (vars->map)
// 		free_map(vars->map);
// }
