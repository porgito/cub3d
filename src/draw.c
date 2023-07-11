/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:42:14 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/11 21:42:14 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img.addr + (y * info->img.len + x * (info->img.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	paint_bg(t_info *info)
{
	int	w;
	int	h;

	h = -1;
	while (++h < HAUTEUR)
	{
		w = -1;
		while (++w < LARGEUR)
		{
			if (h < HAUTEUR / 2)
				my_mlx_pixel_put(info, w, h, info->ceiling);
			else
				my_mlx_pixel_put(info, w, h, info->floor);
		}
	}
}

static void	paint_walls(t_info *info, t_texture *texture, t_ray *r, int x)
{
	int	y;
	int	color;

	r->tex_step = 1.0 * info->texture->img_height / r->line_height;
	r->tex_pos = (r->draw_start - HAUTEUR / 2 \
		+ r->line_height / 2) * r->tex_step;
	y = r->draw_start - 1;
	texture->colors = (int *)mlx_get_data_addr(texture->img.ptr, \
		&texture->img.bpp, &texture->img.len, &texture->img.endian);
	while (++y < r->draw_end)
	{
		r->tex_y = (int)r->tex_pos;
		r->tex_pos += r->tex_step;
		color = texture->colors[texture->img_height * r->tex_y + r->tex_x];
		my_mlx_pixel_put(info, x, y, color);
	}
}

static void	painting(t_info *info, t_ray *r, int x)
{
	if (r->raydir_y < 0 && r->side == Y_SIDE)
		paint_walls(info, &info->texture[0], r, x);
	else if (r->raydir_y > 0 && r->side == Y_SIDE)
		paint_walls(info, &info->texture[1], r, x);
	else if (r->raydir_x < 0 && r->side == X_SIDE)
		paint_walls(info, &info->texture[2], r, x);
	else if (r->raydir_x > 0 && r->side == X_SIDE)
		paint_walls(info, &info->texture[3], r, x);
}

int	paint_map(t_info *info)
{
	int		x;
	t_ray	r;

	mlx_clear_window(info->mlx, info->win);
	paint_bg(info);
	x = -1;
	while (++x < LARGEUR)
	{
		init_raycasting_info(info, &r, x);
		init_side_dist(info, &r);
		raycasting(info, &r);
		init_perp_dist(info, &r);
		init_draw_ypoints(&r);
		if (info->mapi[r.cur_y][r.cur_x] == '1')
			painting(info, &r, x);
	}
	paint_minimap(info, info->map_x * MINIMAP_S, info->map_y * MINIMAP_S);
	mlx_put_image_to_window(info->mlx, info->win, info->img.ptr, 0, 0);
	return (0);
}