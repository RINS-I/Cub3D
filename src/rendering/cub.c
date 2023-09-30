/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/30 21:04:33 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
{
	map->coor.px = 0;
	map->coor.py = 0;
	//map->coor.angle = 0;
	map->wall.x = 0;
	map->wall.y = 0;
	map->coor.put = 0;
}

int	exit_prog(void)
{
	return (0);
}

void	init_mlx(t_map	*map)
{
	init_map(map);
	map->mlx = mlx_init();
	map->mlx_win1 = mlx_new_window(map->mlx, map->coor.x * 64, map->coor.y * 64,
					"cub2d");
	map->img.img = mlx_new_image(map->mlx, map->coor.x * 64, map->coor.y * 64);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
					&map->img.line_length, &map->img.endian);

	map->mlx_win = mlx_new_window(map->mlx, W_WIN, H_WIN,
					"cub3d");
	map->image.img = mlx_new_image(map->mlx, W_WIN, H_WIN);
	map->image.addr = mlx_get_data_addr(map->image.img, &map->image.bits_per_pixel,
					&map->image.line_length, &map->image.endian);

	put_pixel(map);
	mlx_hook(map->mlx_win1, 2, 1L<<0, key, map);
	mlx_hook(map->mlx_win, 2, 1L<<0, key, map);
	mlx_hook(map->mlx_win1, 17, 1L<<0, exit_prog, map);
	mlx_hook(map->mlx_win, 17, 1L<<0, exit_prog, map);
	mlx_loop(map->mlx);
}
