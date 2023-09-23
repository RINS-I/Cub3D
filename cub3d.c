/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/23 17:33:00 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->map = malloc (sizeof(char *) * 10);
	map->map[0] = "11111111111";
	map->map[1] = "10010001001";
	map->map[2] = "10000000001";
	map->map[3] = "100N0001001";
	map->map[4] = "10000000001";
	map->map[5] = "10001000001";
	map->map[6] = "10001000001";
	map->map[7] = "10001000001";
	map->map[8] = "10001000001";
	map->map[9] = "11111111111";
	map->coor.x = strlen(map->map[0]);
	map->coor.y = 10;
	map->coor.new_i = 0;
	map->coor.new_j = 0;
	map->coor.angle = 0;
	map->coor.put = 0;
	map->coor.d = 0;
	map->coor.d_h = 0;
	map->coor.d_v = 0;
	map->wall.x = 0;
	map->wall.y = 0;
	map->wall.h_x = 0;
	map->wall.h_y = 0;
	map->wall.gh_x = 0;
	map->wall.gh_y = 0;
	map->wall.gv_x= 0;
	map->wall.gv_y = 0;
	map->wall.v_x = 0;
	map->wall.v_y = 0;
}


int	exit_prog(void)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	(void)ac;
	(void)av;
	init_map(&map);

	//////////////////2D////////////////////////////////////////

	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.coor.x * 64, map.coor.y * 64,
					"cub2d");
	map.img.img = mlx_new_image(map.mlx, map.coor.x * 64, map.coor.y * 64);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel,
					&map.img.line_length, &map.img.endian);

	////////////////3D//////////////////////////////////////////

	map.mlx_win1 = mlx_new_window(map.mlx, W_WIN, H_WIN,
					"cub3d");
	map.image.img = mlx_new_image(map.mlx, W_WIN, H_WIN);
	map.image.addr = mlx_get_data_addr(map.image.img, &map.image.bits_per_pixel,
					&map.image.line_length, &map.image.endian);
	put_pixel(&map);

	//////////////////////////////////////////////////////////////////

	mlx_hook(map.mlx_win, 2, 1L<<0, key, &map);
	mlx_hook(map.mlx_win1, 2, 1L<<0, key, &map);
	mlx_hook(map.mlx_win, 17, 1L<<0, exit_prog, &map);
	mlx_hook(map.mlx_win1, 17, 1L<<0, exit_prog, &map);
	mlx_loop(map.mlx);
	return (0);
}
