/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/08 17:57:06 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
#define RENDERING_H

# define A 97
# define S 115
# define W 119
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362
# define H_WIN 641.0
# define W_WIN 1007.0
#define	SPEED 7

typedef struct t_mini
{
	int	f;
	int	e;
}		t_mini;

typedef struct t_textures
{
	double	x;
	double	y;
	int		direction;
}			t_textures;

typedef struct t_coor
{
	int		x;
	int		y;
	int		py;
	int		px;
	int		m_x;
	int		m_y;
	int		put;
	double	d_h;
	double	d_v;
	double	d;
	double	angle;
	int		up;
	int		down;
	int		right;
	int		left;
	int		flag_a;
	int		coll;
}			t_coor;

typedef struct t_image
{
	int		w_img;
	int		h_img;
	void	*img;
	void	*img_n;
	void	*img_e;
	void	*img_s;
	void	*img_w;
	void	*img_d[10];
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

typedef struct t_sprt
{
	int	x;
	int	y;
	int	i_x;
	int	i_y;
	int	j_x;
	int	j_y;
	int	t_y;
	int	t_x;
	int	timer;
}		t_sprt;

typedef struct t_map
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_win1;
	char		**map;
	t_coor		coor;
	t_wall		wall;
	t_image		image;
	t_image		img;
	t_image		textures;
	t_image		sprit;
	t_data		*data;
	t_textures	txt;
	t_mini		mini;
	t_sprt		sprt;
}				t_map;

void			rendering(t_map *map);
void			put_pixel(t_map *map);
void			my_mlx_put_pixel(t_image *img, int x, int y, int color);
int				key(int key_code, t_map *map);
void			get_dist_wall(t_map *map);
void			mouve_player(t_map *map, int x, int y);
int				player_collisions(t_map *map, int x, int y);
int				check_if_wall(t_map *map, int x, int y);
void			draw_walls(t_map *map, double angle);
void			fill_map3(t_map *map);
void			inter_ver_wall(t_map *map, double angle);
void			inter_hori_wall(t_map *map, double angle);
void			coor_of_ver_wall(t_map *map,double x,double y);
void			coor_of_hor_wall(t_map *map, double x, double y);
double			distance_wall(t_map *map, double x, double y);
void			init_map(t_map *map);
void			fill_cub_p(t_map *map, int x, int y, int color);
int				close_win(void);
void			fill_minimap(t_map *map);
int				mouse_key(int key_code, int x, int y, t_map *map);
unsigned int	convert_color(int r, int g, int b);
void			get_coor_player(t_map *map);
int	animation(t_map *map);


void	draw_rays(t_map *map, double angle);

#endif
