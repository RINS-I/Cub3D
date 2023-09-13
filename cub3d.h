/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/13 18:41:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

# define A 97
# define S 65364
# define W 119
# define D 100
# define ESC 53

typedef struct t_coor
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	new_i;
	int	new_j;
}		t_coor;


typedef struct t_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct t_map
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_coor	coor;
	t_image	img;
}			t_map;

void	put_pixel(t_map *map);
void	fill_cub_player(t_map *map, int i, int j, int color);
void	fill_cub_pixels(t_map *map, int i, int j, int color);
void	my_mlx_put_pixel(t_image *img, int x, int y, int color);
int		key(int key_code, t_map *map);

#endif
