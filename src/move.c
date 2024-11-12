/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:35:18 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:46:29 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	move_forward(t_vars *vars)
{
	int	y;
	int	x;

	y = (int)(vars->data->p_pos_y + vars->data->p_ori_y * 0.4);
	x = (int)vars->data->p_pos_x;
	if (vars->map[y][x] != '1')
		vars->data->p_pos_y += vars->data->p_ori_y * 0.4;
	y = (int)vars->data->p_pos_y;
	x = (int)(vars->data->p_pos_x + vars->data->p_ori_x * 0.4);
	if (vars->map[y][x] != '1')
		vars->data->p_pos_x += vars->data->p_ori_x * 0.4;
	vars->pos_p.y = vars->data->p_pos_y;
	vars->pos_p.x = vars->data->p_pos_x;
}

void	move_back(t_vars *vars)
{
	int	y;
	int	x;

	y = (int)(vars->data->p_pos_y - vars->data->p_ori_y * 0.2);
	x = (int)vars->data->p_pos_x;
	if (vars->map[y][x] != '1')
		vars->data->p_pos_y -= vars->data->p_ori_y * 0.2;
	y = (int)vars->data->p_pos_y;
	x = (int)(vars->data->p_pos_x - vars->data->p_ori_x * 0.2);
	if (vars->map[y][x] != '1')
		vars->data->p_pos_x -= vars->data->p_ori_x * 0.2;
	vars->pos_p.y = vars->data->p_pos_y;
	vars->pos_p.x = vars->data->p_pos_x;
}

void	move_left(t_vars *vars)
{
	int		y;
	int		x;

	y = (int)(vars->data->p_pos_y - vars->data->plane_y * 0.3);
	x = (int)vars->data->p_pos_x;
	if (vars->map[y][x] != '1')
		vars->data->p_pos_y -= vars->data->plane_y * 0.3;
	y = (int)vars->data->p_pos_y;
	x = (int)(vars->data->p_pos_x - vars->data->plane_x * 0.3);
	if (vars->map[y][x] != '1')
		vars->data->p_pos_x -= vars->data->plane_x * 0.3;
	vars->pos_p.y = vars->data->p_pos_y;
	vars->pos_p.x = vars->data->p_pos_x;
}

void	move_right(t_vars *vars)
{
	int		y;
	int		x;

	y = (int)(vars->data->p_pos_y + vars->data->plane_y * 0.3);
	x = (int)vars->data->p_pos_x;
	if (vars->map[y][x] != '1')
		vars->data->p_pos_y += vars->data->plane_y * 0.3;
	y = (int)vars->data->p_pos_y;
	x = (int)(vars->data->p_pos_x + vars->data->plane_x * 0.3);
	if (vars->map[y][x] != '1')
		vars->data->p_pos_x += vars->data->plane_x * 0.3;
	vars->pos_p.y = vars->data->p_pos_y;
	vars->pos_p.x = vars->data->p_pos_x;
}

	// 119 = W | 115 = S | 100 = D | 97 = A
void	ft_move(t_vars *vars, int keycode)
{
	if (keycode == 119)
		move_forward(vars);
	if (keycode == 115)
		move_back(vars);
	if (keycode == 97)
		move_left(vars);
	if (keycode == 100)
		move_right(vars);
}
