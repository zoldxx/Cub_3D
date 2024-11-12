/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:52:38 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:52:48 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	rotate_right(t_vars *vars, double old_dir_x)
{
	double	old_plane_x;

	vars->data->p_ori_x = vars->data->p_ori_x * cos(0.05)
		- vars->data->p_ori_y * sin(0.05);
	vars->data->p_ori_y = vars->data->p_ori_y * cos(0.05)
		+ old_dir_x * sin(0.05);
	old_plane_x = vars->data->plane_x;
	vars->data->plane_x = vars->data->plane_x * cos(0.05)
		- vars->data->plane_y * sin(0.05);
	vars->data->plane_y = vars->data->plane_y * cos(0.05)
		+ old_plane_x * sin(0.05);
}

void	rotate_left(t_vars *vars, double old_dir_x)
{
	double	old_plane_x;

	vars->data->p_ori_x = vars->data->p_ori_x * cos(-0.05)
		- vars->data->p_ori_y * sin(-0.05);
	vars->data->p_ori_y = vars->data->p_ori_y * cos(-0.05)
		+ old_dir_x * sin(-0.05);
	old_plane_x = vars->data->plane_x;
	vars->data->plane_x = vars->data->plane_x * cos(-0.05)
		- vars->data->plane_y * sin(-0.05);
	vars->data->plane_y = vars->data->plane_y * cos(-0.05)
		+ old_plane_x * sin(-0.05);
}
