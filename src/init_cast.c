/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:21 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:48:35 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_north_or_south(t_vars *vars, char sens)
{
	if (sens == 'N')
	{
		vars->data->p_ori_x = 0;
		vars->data->p_ori_y = -1;
		vars->data->plane_x = 0.66;
		vars->data->plane_y = 0;
	}
	else if (sens == 'S')
	{
		vars->data->p_ori_x = 0;
		vars->data->p_ori_y = 1;
		vars->data->plane_x = -0.66;
		vars->data->plane_y = 0;
	}
}

void	init_data_game(t_vars *vars, char sens)
{
	if (sens == 'N' || sens == 'S')
		init_north_or_south(vars, sens);
	else if (sens == 'W')
	{
		vars->data->p_ori_x = -1;
		vars->data->p_ori_y = 0;
		vars->data->plane_x = 0;
		vars->data->plane_y = -0.66;
	}
	else if (sens == 'E')
	{
		vars->data->p_ori_x = 1;
		vars->data->p_ori_y = 0;
		vars->data->plane_x = 0;
		vars->data->plane_y = 0.66;
	}
}

void	define_pos_player(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < vars->nb_line_map)
	{
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == 'N' || vars->map[y][x] == 'S'
				|| vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
			{
				vars->pos_p.x = x + 0.5;
				vars->pos_p.y = y + 0.5;
				vars->pos_p.sens = vars->map[y][x];
				break ;
			}
		}
		x = -1;
	}
	init_data_game(vars, vars->pos_p.sens);
}
