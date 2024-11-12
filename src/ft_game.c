/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:42:47 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 17:20:54 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_rotate_pov(t_vars *vars, int keycode)
{
	double	old_dir_x;

	old_dir_x = vars->data->p_ori_x;
	if (keycode == 101 || keycode == 65363)
		rotate_right(vars, old_dir_x);
	else if (keycode == 113 || keycode == 65361)
		rotate_left(vars, old_dir_x);
}

int	ft_keymove(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		free_all(vars);
		exit (0);
	}
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		ft_move(vars, keycode);
	if (keycode == 101 || keycode == 113
		|| keycode == 65363 || keycode == 65361)
		ft_rotate_pov(vars, keycode);
	return (1);
}

int	ft_key_hook(t_vars *vars)
{
	free_all(vars);
	exit (0);
}

t_vars	initialise_var(t_vars *vars)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	(void)img;
	vars->pos_p.rad = 0;
	vars->pi = M_PI;
	vars->pos_p.sens = 1;
	return (*vars);
}

void	ft_game(t_vars *game)
{
	game->nb_line_map = ft_nb_line(game->map);
	game->size_line = ft_size_line(game->map, game->nb_line_map);
	game->image = malloc(sizeof(t_img));
	if (!game->image)
		return ;
	game->image->img = NULL;
	define_pos_player(game);
	mlx_hook(game->win, 17, 0, ft_key_hook, game);
	mlx_hook(game->win, 2, 1L << 0, ft_keymove, game);
	mlx_loop_hook(game->mlx, ft_ray_casting_rework, game);
	mlx_loop(game->mlx);
}
