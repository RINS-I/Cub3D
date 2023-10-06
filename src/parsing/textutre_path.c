/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textutre_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:06:36 by xshel             #+#    #+#             */
/*   Updated: 2023/10/06 11:18:05 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int    check_texture_path(t_data *data)
{
    int i;

    i = 0;
    char **tmp;

    tmp = NULL;
    data->files->d_spl = ft_split(data->files->d, '\n');
    while (data->files->d_spl[i])
    {
        tmp = ft_split(data->files->d_spl[i], ' ');
        if (ft_strcmp(tmp[0], "NO") == 0 || ft_strcmp(tmp[0], "SO") == 0 ||
                    ft_strcmp(tmp[0], "WE") == 0 || ft_strcmp(tmp[0], "EA") == 0)
        {
            if (open(tmp[1], O_RDONLY))
                return 1;
            else
                return 0;
        }
        free(tmp[0]);
        free(tmp[1]);
        free(tmp);
        i++;
    }
    return 0;
}