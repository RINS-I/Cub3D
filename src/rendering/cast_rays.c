/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:52:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/06 18:58:36 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_map3(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_WIN)
	{
		j = 0;
		while (j < H_WIN)
		{
			my_mlx_put_pixel(&map->image, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

unsigned int	get_color(t_map *map, int x, int y)
{
	return (*(unsigned int *)(map->textures.addr + y * map->textures.line_length
		+ x * (map->textures.bits_per_pixel / 8)));
}

void	draw_walls(t_map *map, double angle)
{
	int	j;
	int	start;
	int	end;
	int	color;

	map->wall.wall_height = ceil(64 * W_WIN / (fabs(2 * tan(M_PI / 6)
		* (map->coor.d * cos(angle - map->coor.angle)))));
	start = (H_WIN / 2) - (map->wall.wall_height / 2);
	end = (H_WIN / 2) + (map->wall.wall_height / 2);
	if (start < 0)
		start = 0;
	j = 0;
	while (j < H_WIN)
	{
		if (j <= (H_WIN / 2) - (map->wall.wall_height / 2))
		{
			color = convert_color(map->data->c_c->c->r, map->data->c_c->c->g,
				map->data->c_c->c->b);
			my_mlx_put_pixel(&map->image, map->wall.x, map->wall.y + j,color);
		}
		if (start < end)
		{
			map->txt.y = (start - (H_WIN / 2) + (map->wall.wall_height / 2)) * 64.0 / map->wall.wall_height;
			my_mlx_put_pixel(&map->image, map->wall.x, map->wall.y + start, get_color(map, map->txt.x, map->txt.y));
			start++;
		}
		if (j >= end)
		{
			color = convert_color(map->data->c_c->f->r, map->data->c_c->f->g,
				map->data->c_c->f->b);
			my_mlx_put_pixel(&map->image, map->wall.x, map->wall.y + j, color);
		}
		j++;
	}
}
