/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initraycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:40:44 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/01 13:40:44 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_texture(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		info->texture[i].file_name = 0;
		info->texture[i].img_height = 0;
		info->texture[i].img_width = 0;
	}
}

void	initinfo3(t_info *info, char *map_name)
{	
	info->floor = -1;
	info->ceiling = -1;
	info->map_x = -1;
	info->map_y = -1;
	info->angle = 30 * PI / 180;
	info->mlx = mlx_init();
	if (!info->mlx)
		error(info, "MLX INIT");
	init_texture(info);
}