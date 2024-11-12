/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:59 by jquil             #+#    #+#             */
/*   Updated: 2024/01/08 16:57:01 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct pos_and_sens_player
{
	float		x;
	float		y;
	char		sens;
	float		rad;
}				t_pasp;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			rowlen;
	int			endian;
	int			tex_width;
	int			tex_height;
}				t_img;

typedef struct s_ray
{
	double		camera;
	double		diray_x;
	double		diray_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		ray_length;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_data
{
	double	p_pos_x;
	double	p_pos_y;
	double	p_ori_x;
	double	p_ori_y;
	double	plane_x;
	double	plane_y;
	double	cur_time;
	double	old_time;
	int		texture;
}			t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	char			**map;
	unsigned int	win_x;
	unsigned int	win_y;
	int				nb_line_map;
	int				*size_line;
	long double		pi;
	int				limit_ceil;
	int				limit_wall;
	int				limit_screen;
	int				*floor;
	int				*roof;
	int				rgb_floor;
	int				rgb_ceiling;
	t_img			*north_wall;
	t_img			*south_wall;
	t_img			*east_wall;
	t_img			*west_wall;
	t_img			*image;
	t_pasp			pos_p;
	t_ray			*ray;
	t_data			*data;
}				t_vars;

//---- Parsing ---//

int				ft_ray_casting_rework(t_vars *vars);
int				ft_extract_map_for_parse(char *file);
int				ft_keymove(int keycode, t_vars *vars);
int				ft_nb_line(char **map);
int				*ft_size_line(char **map, int nb_line);
void			ft_ray_casting(t_vars *vars);
void			define_pos_player(t_vars *vars);
int				ft_nb_line_empty(char *file);
void			free_map(char **map);
void			ft_clear_mlx(t_vars *vars);
char			*ft_strjoin(char *s1, char *s2);
void			ft_game(t_vars *game);

// parsing dav
int				check_textures(char **map, char **textures, int i, int *k);
int				char_is_desc_or_fc(char **map, int i, int k);
int				valid_description(char **map);
int				is_char_desc(char c, char d);
int				already_exist(char **textures, char **map, int i, int k);
int				get_image_name(char **map, char *str, int i, int k);
int				valid_image(char **map, int i, int k);
int				atoi(const char *str);
int				check_len_nb(char **map, int i, int *k, int *j);
int				skip_space(char **map, int i, int *k, int *nb_tour);
void			reset_k(char **map, int i, int *k);
int				valid_fc(char **map, int i, int k);
int				textures_good(char **textures);
char			**calloc_textures(void);
char			**init_textures(void);
void			update_textures(char **textures, char **map, int i);
int				line_walled(char *str);
int				space_walled(char **map, int i, int k);
int				is_walled(char **map);
int				valid_map(char **file);
int				valid_parsing(char *av);
int				fl_line_walled(char *line);
int				find_start_map(char **file, int *i, int *k);
int				valid_char(char **file, int i, int k);
char			**extract_map(char **file, char **map, int i);
char			**get_map(char *av);
int				valid_name(char *str);
int				len(char *str);
int				contain_wall(char *str);
int				extract_line(char *map_line, char *file_line, int longest);
int				longest_line(char **file, int i);

// init game
int				init_game(t_vars *game, char *filename);
void			free_all(t_vars *game);
int				set_var_null(t_vars *game);
int				contain_texture(char *str);
int				load_images(t_vars *game, char *str, char dir, int i);
int				extract_image(t_vars *game, char **file, int i, int k);
void			put_color_in_struct(t_vars *game, char c, int color, char *nb);
void			init_extract(char **file, int i, int *k, int *color);
int				extract_fc(t_vars *game, char **file, int i, int k);
int				extract_textures(t_vars *game, char **file);
int				init_mlx(t_vars *game);
int				init_map(t_vars *game, char **file);
void			ft_move(t_vars *vars, int keycode);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int				get_color(t_vars *vars, int x, int y);
void			rotate_right(t_vars *vars, double old_dir_x);
void			rotate_left(t_vars *vars, double old_dir_x);
int				choose_text(t_vars *vars);
void			set_var_for_raycast(t_vars *vars);

// flood fill
int				replace_two(char **map, int i, int k);
int				flood_fill(char **map);
int				size_min(char **map);
char			**copy_map(char **map);
int				find_player(char **map, int *i, int *k);
int				contain_two(char **map);
int				find_two(char **map, int *i, int *k);

// GNL dav
char			*get_line(char *full_line);
char			*reserve(char *full_line);
char			*get_full_line(int fd, char *full_line);
char			*get_next_line(int fd, int flag);
char			*ft_strjoin(char *s1, char *s2);

int				get_rgb(int *rgb);

#endif
