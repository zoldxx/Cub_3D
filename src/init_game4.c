/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:34:27 by dberreby          #+#    #+#             */
/*   Updated: 2023/12/20 16:35:14 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	contain_texture(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E'
		|| str[i] == 'F' || str[i] == 'C')
		return (1);
	return (0);
}

int	load_images2(t_vars *vars, char *str, char dir, int i)
{
	(void)i;
	if (dir == 'E')
	{
		vars->east_wall->img = mlx_xpm_file_to_image(vars->mlx,
				str, &vars->east_wall->tex_width,
				&vars->east_wall->tex_height);
		if (!vars->east_wall->img)
			return (0);
	}
	if (dir == 'W')
	{
		vars->west_wall->img = mlx_xpm_file_to_image(vars->mlx,
				str, &vars->west_wall->tex_width,
				&vars->west_wall->tex_height);
		if (!vars->west_wall->img)
			return (0);
	}
	return (1);
}

int	load_images(t_vars *vars, char *str, char dir, int i)
{
	(void)i;
	if (dir == 'N')
	{
		vars->north_wall->img = mlx_xpm_file_to_image(vars->mlx,
				str, &vars->north_wall->tex_width,
				&vars->north_wall->tex_height);
		if (!vars->north_wall->img)
			return (0);
	}
	else if (dir == 'S')
	{
		vars->south_wall->img = mlx_xpm_file_to_image(vars->mlx,
				str, &vars->south_wall->tex_width,
				&vars->south_wall->tex_height);
		if (!vars->south_wall->img)
			return (0);
	}
	return (load_images2(vars, str, dir, i));
}
