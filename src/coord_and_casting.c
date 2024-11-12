/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_and_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:22 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:56:00 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	create_img_for_print(t_vars *vars, int x_pixel)
{
	int	y_pixel;

	y_pixel = 0;
	vars->data->texture = choose_text(vars);
	set_var_for_raycast(vars);
	y_pixel = vars->ray->draw_start;
	while (y_pixel >= 0)
	{
		my_mlx_pixel_put(vars, x_pixel, y_pixel, vars->rgb_ceiling);
		y_pixel--;
	}
	y_pixel = vars->ray->draw_start;
	while (y_pixel <= vars->ray->draw_end)
	{
		my_mlx_pixel_put(vars, x_pixel, y_pixel,
			get_color(vars, vars->ray->tex_x, vars->ray->tex_pos));
		vars->ray->tex_pos += vars->ray->step;
		y_pixel++;
	}
	while (y_pixel < (int)vars->win_y)
	{
		my_mlx_pixel_put(vars, x_pixel, y_pixel, vars->rgb_floor);
		y_pixel++;
	}
}

void	set_camera(t_vars *vars, t_ray *ray, int x)
{
	ray->camera = 2 * x / (double)vars->win_x - 1;
	ray->diray_x = vars->data->p_ori_x + vars->data->plane_x * ray->camera;
	ray->diray_y = vars->data->p_ori_y + vars->data->plane_y * ray->camera;
	ray->map_x = (int)vars->pos_p.x;
	ray->map_y = (int)vars->pos_p.y;
	if (ray->diray_x != 0)
		ray->delta_dist_x = fabs(1 / ray->diray_x);
	else
		ray->delta_dist_x = INT_MAX;
	if (ray->diray_y != 0)
		ray->delta_dist_y = fabs(1 / ray->diray_y);
	else
		ray->delta_dist_y = INT_MAX;
}

void	set_sidedist(t_vars *vars)
{
	if (vars->ray->diray_x < 0)
	{
		vars->ray->step_x = -1;
		vars->ray->side_dist_x = (vars->data->p_pos_x
				- vars->ray->map_x) * vars->ray->delta_dist_x;
	}
	else
	{
		vars->ray->step_x = 1;
		vars->ray->side_dist_x = (vars->ray->map_x + 1
				- vars->data->p_pos_x) * vars->ray->delta_dist_x;
	}
	if (vars->ray->diray_y < 0)
	{
		vars->ray->step_y = -1;
		vars->ray->side_dist_y = (vars->data->p_pos_y
				- vars->ray->map_y) * vars->ray->delta_dist_y;
	}
	else
	{
		vars->ray->step_y = 1;
		vars->ray->side_dist_y = (vars->ray->map_y + 1
				- vars->data->p_pos_y) * vars->ray->delta_dist_y;
	}
}

void	check_hit(t_vars *vars, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (vars->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->ray_length = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->ray_length = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = vars->win_y / (ray->ray_length);
}

int	ft_ray_casting_rework(t_vars *vars)
{
	int	x_pixel;

	x_pixel = 0;
	if (vars->image->img)
	{
		mlx_destroy_image(vars->mlx, vars->image->img);
		vars->image->img = NULL;
	}
	vars->image->img = mlx_new_image(vars->mlx, vars->win_x, vars->win_y);
	vars->image->addr = mlx_get_data_addr(vars->image->img,
			&vars->image->bpp, &vars->image->rowlen, &vars->image->endian);
	while (x_pixel < (int)vars->win_x)
	{
		set_camera(vars, vars->ray, x_pixel);
		vars->data->p_pos_y = vars->pos_p.y;
		vars->data->p_pos_x = vars->pos_p.x;
		set_sidedist(vars);
		check_hit(vars, vars->ray);
		create_img_for_print(vars, x_pixel);
		x_pixel++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image->img, 0, 0);
	return (1);
}
