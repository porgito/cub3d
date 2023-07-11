/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:40:19 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/07 20:40:19 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_texture_info(t_info *info, char **texture, int texture_id)
{
	if (info->texture[texture_id].file_name)
		error(info, "Texture identifier cannot be duplicated");
	info->texture[texture_id].file_name = ft_strdup(texture[1]);
	info->texture[texture_id].img.ptr = mlx_xpm_file_to_image(info->mlx, \
		info->texture[texture_id].file_name, \
		&info->texture[texture_id].img_width, \
		&info->texture[texture_id].img_height);
	if (!info->texture[texture_id].img.ptr)
		error(info, "Texture file does not exist");
}