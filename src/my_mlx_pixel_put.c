/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:00 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:50:27 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*pixel;

	pixel = NULL;
	if (y < 0 || y > (int)vars->win_y - 1 || x < 0 || x > (int)vars->win_x - 1)
		return ;
	pixel = (vars->image->addr + (y * vars->image->rowlen
				+ x * (vars->image->bpp / 8)));
	*(unsigned int *)pixel = color;
}

int	get_rgb(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	get_color(t_vars *vars, int x, int y)
{
	if (vars->data->texture == 0)
		return (*(int *)((vars->north_wall->addr)
			+ (y * vars->north_wall->rowlen
				+ x * (vars->north_wall->bpp / 8))));
	else if (vars->data->texture == 1)
		return (*(int *)((vars->south_wall->addr)
			+ (y * vars->south_wall->rowlen
				+ x * (vars->south_wall->bpp / 8))));
	else if (vars->data->texture == 2)
		return (*(int *)((vars->west_wall->addr)
			+ (y * vars->west_wall->rowlen + x * (vars->west_wall->bpp / 8))));
	else if (vars->data->texture == 3)
		return (*(int *)((vars->east_wall->addr)
			+ (y * vars->east_wall->rowlen + x * (vars->east_wall->bpp / 8))));
	return (0);
}
