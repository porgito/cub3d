/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:50:04 by jlaurent          #+#    #+#             */
/*   Updated: 2023/06/30 13:50:04 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_perp_dist(t_info *info, t_ray *r)
{
	if (r->side == X_SIDE)
	{
		r->perp_wall_dist = (r->cur_x - info->pos_x \
			+ (1 - r->step_x) / 2) / r->raydir_x;
		r->wall_x = info->pos_y + r->perp_wall_dist * r->raydir_y;
	}
	else if (r->side == Y_SIDE)
	{
		r->perp_wall_dist = (r->cur_y - info->pos_y \
			+ (1 - r->step_y) / 2) / r->raydir_y;
		r->wall_x = info->pos_x + r->perp_wall_dist * r->raydir_x;
	}
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double)info->texture->img_width);
	if ((r->side == X_SIDE && r->raydir_x < 0) \
		|| (r->side == Y_SIDE && r->raydir_y > 0))
		r->tex_x = info->texture->img_width - r->tex_x -1;
}

void	init_draw_ypoints(t_ray *r)
{
	r->line_height = (int)((HAUTEUR / 2) / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + HAUTEUR / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + HAUTEUR / 2;
	if (r->draw_end >= HAUTEUR)
		r->draw_end = HAUTEUR - 1;
}

void	raycasting(t_info *info, t_ray *r)
{
	r->hit = 0;
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->cur_x += r->step_x;
			r->side = X_SIDE;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->cur_y += r->step_y;
			r->side = Y_SIDE;
		}
		if (info->mapi[r->cur_y][r->cur_x] == '1')
			r->hit = 1;
	}
}
