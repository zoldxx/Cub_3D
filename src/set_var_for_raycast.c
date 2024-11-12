/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_for_raycast.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:56:11 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:56:21 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	choose_text(t_vars *vars)
{
	if (vars->ray->side == 0 && vars->ray->diray_x < 0)
		return (3);
	else if (vars->ray->side == 0 && vars->ray->diray_x > 0)
		return (2);
	else if (vars->ray->side == 1 && vars->ray->diray_y < 0)
		return (1);
	else if (vars->ray->side == 1 && vars->ray->diray_y > 0)
		return (0);
	return (0);
}

void	vars_for_ns(t_vars *vars, int x)
{
	if (x == 0)
	{
		vars->ray->tex_x = (int)(vars->ray->wall_x
				* (double)vars->north_wall->tex_width);
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0)
			|| (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->north_wall->tex_width
				- vars->ray->tex_x - 1;
		vars->ray->step = 1 * (double)vars->north_wall->tex_height
			/ vars->ray->line_height;
	}
	if (x == 1)
	{
		vars->ray->tex_x = (int)(vars->ray->wall_x
				* (double)vars->south_wall->tex_width);
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0)
			|| (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->south_wall->tex_width
				- vars->ray->tex_x - 1;
		vars->ray->step = 1 * (double)vars->south_wall->tex_height
			/ vars->ray->line_height;
	}
}

void	vars_for_ew(t_vars *vars, int x)
{
	if (x == 0)
	{
		vars->ray->tex_x = (int)(vars->ray->wall_x
				* (double)vars->west_wall->tex_width);
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0)
			|| (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->west_wall->tex_width
				- vars->ray->tex_x - 1;
		vars->ray->step = 1 * (double)vars->west_wall->tex_height
			/ vars->ray->line_height;
	}
	if (x == 1)
	{
		vars->ray->tex_x = (int)(vars->ray->wall_x
				* (double)vars->east_wall->tex_width);
		if ((vars->ray->side == 0 && vars->ray->diray_x > 0)
			|| (vars->ray->side == 1 && vars->ray->diray_y < 0))
			vars->ray->tex_x = vars->east_wall->tex_width
				- vars->ray->tex_x - 1;
		vars->ray->step = 1 * (double)vars->east_wall->tex_height
			/ vars->ray->line_height;
	}
}

void	set_var_for_raycast(t_vars *vars)
{
	vars->ray->wall_x = 0;
	vars->ray->tex_pos = 0;
	vars->ray->draw_start = -vars->ray->line_height / 2 + vars->win_y / 2;
	if (vars->ray->draw_start < 0 || vars->ray->draw_start > (int)vars->win_y)
		vars->ray->draw_start = 0;
	vars->ray->draw_end = vars->ray->line_height / 2 + vars->win_y / 2;
	if (vars->ray->draw_end >= (int)vars->win_y)
		vars->ray->draw_end = vars->win_y - 1;
	if (vars->ray->side == 0)
		vars->ray->wall_x = vars->data->p_pos_y
			+ vars->ray->ray_length * vars->ray->diray_y;
	else
		vars->ray->wall_x = vars->data->p_pos_x
			+ vars->ray->ray_length * vars->ray->diray_x;
	vars->ray->wall_x -= floor(vars->ray->wall_x);
	if (vars->data->texture == 0)
		vars_for_ns(vars, 0);
	else if (vars->data->texture == 1)
		vars_for_ns(vars, 1);
	else if (vars->data->texture == 2)
		vars_for_ew(vars, 0);
	else if (vars->data->texture == 3)
		vars_for_ew(vars, 1);
	vars->ray->tex_pos = (vars->ray->draw_start - vars->win_y / 2
			+ vars->ray->line_height / 2) * vars->ray->step;
}
