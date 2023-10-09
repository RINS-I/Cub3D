/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:52:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/03 16:15:25 by niboukha         ###   ########.fr       */
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

void	draw_walls(t_map *map, int color, double angle)
{
	int	j;
	int	x;

	x = fabs(2 * tan(M_PI / 6) * (map->coor.d * cos(angle - map->coor.angle)));
	map->wall.wall_height = ceil(64 * W_WIN / x);

	j = (H_WIN / 2) - (map->wall.wall_height / 2);
	if (j < 0)
		j = 0;
	while (j < H_WIN && j < ((H_WIN / 2) + (map->wall.wall_height / 2)))
	{
		my_mlx_put_pixel(&map->image, map->wall.x,
			map->wall.y + j, color);
		j++;
	}
}
