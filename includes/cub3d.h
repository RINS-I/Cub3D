/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:58:47 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/05 00:58:05 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
# include "./lib.h"
# include "./get_next_line.h"
#include "./parsing.h"
#include "./rendering.h"
#include "./mlxx.h"

int		parsing(t_data data, t_map *map, int fd);
void	init_mlx(t_map	*map);
void    texture(t_map *map);

#endif