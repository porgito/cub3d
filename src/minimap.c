/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:38:11 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/11 21:38:11 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_redrange(t_info *info, int w, int h)
{
	int	width;
	int	height;

	width = info->map_x * MINIMAP_S;
	height = info->map_y * MINIMAP_S;
	if (((info->pos_x * MINIMAP_S > w \
		&& info->pos_x * MINIMAP_S < w + 3) \
		&& (info->pos_y * MINIMAP_S > h \
		&& info->pos_y * MINIMAP_S < h + 3)) \
		|| h == 0 || h == height - 1 || w == 0 || w == width - 1)
		return (1);
	return (0);
}

static void	painting_minimap(t_info *info, int w, int h)
{
	int	cx;
	int	cy;

	cx = w / MINIMAP_S;
	cy = h / MINIMAP_S;
	if (is_redrange(info, w, h))
		my_mlx_pixel_put(info, w + MINIMAP_S / 2, \
		h + MINIMAP_S / 2, 0xff0000);
	else if (info->mapi[cy][cx] == '1')
		my_mlx_pixel_put(info, w + MINIMAP_S / 2, \
			h + MINIMAP_S / 2, 0xa0a0a0);
	else if (info->mapi[cy][cx] == -1)
		my_mlx_pixel_put(info, w + MINIMAP_S / 2, \
			h + MINIMAP_S / 2, info->ceiling);
	else
		my_mlx_pixel_put(info, w + MINIMAP_S / 2, \
			h + MINIMAP_S / 2, info->floor);
}

void	paint_minimap(t_info *info, int width, int height)
{
	int	h;
	int	w;

	h = -1;
	while (++h < height)
	{
		w = -1;
		while (++w < width)
		{
			painting_minimap(info, w, h);
		}
	}
}