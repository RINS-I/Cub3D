/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/30 20:54:09 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
#define RENDERING_H

# define A 97
# define S 115
# define W 119
# define D 100
# define ESC 53
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362
# define H_WIN 641.0
# define W_WIN 1007.0

typedef struct t_coor
{
	int		x;
	int		y;
	int		py;
	int		px;
	int		put;
	double	d_h;
	double	d_v;
	double	d;
	double	angle;
}				t_coor;

typedef struct t_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct t_wall
{
	int		x;
	int		y;
	double	h_x;
	double	h_y;
	double	gh_x;
	double	gh_y;
	double	v_x;
	double	v_y;
	double	gv_x;
	double	gv_y;
	double	wall_height;
}			t_wall;

typedef struct t_map
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_win1;
	char	**map;
	t_coor	coor;
	t_wall	wall;
	t_image	image;
	t_image	img;
}			t_map;

void	put_pixel(t_map *map);
void	fill_cub_player(t_map *map, int x, int y, int color);
void	fill_cub_pixels(t_map *map, int x, int y, int color);
void	my_mlx_put_pixel(t_image *img, int x, int y, int color);
int		key(int key_code, t_map *map);
void	get_dist_wall(t_map *map, int color);
void	move_player(t_map *map, int x, int y);
int		player_collisions(t_map *map, int x, int y);
int		check_if_wall(t_map *map, int x, int y);
void	draw_walls(t_map *map, int color, double angle);
void	fill_map3(t_map *map);

void	inter_ver_wall(t_map *map, double angle);
void	inter_hori_wall(t_map *map, double angle);

void	coor_of_ver_wall(t_map *map,double x,double y);
void	coor_of_hor_wall(t_map *map, double x, double y);

void	draw_rays(t_map *map, double angle);
double	distance_wall(t_map *map, double x, double y);



void	fill_cub_pxl(t_map *map, int x, int y, int color);
void	fill_cub_p(t_map *map, int x, int y, int color);

int	exit_prog(void);

#endif
