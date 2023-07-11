/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initraycast2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:55:56 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/07 19:55:56 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_dirplane(t_info *info, int idx)
{
	const double	dir_x[4] = {0.0, 0.0, -1.0, 1.0};
	const double	dir_y[4] = {-1.0, 1.0, 0.0, 0.0};
	const double	plane_x[4] = {0.66, -0.66, 0.0, 0.0};
	const double	plane_y[4] = {0.0, 0.0, -0.66, 0.66};

	info->p.dir_x = dir_x[idx];
	info->p.dir_y = dir_y[idx];
	info->p.plane_x = plane_x[idx];
	info->p.plane_y = plane_y[idx];
}

void	init_player(t_info *info)
{
	if (info->spawn == 'N')
		init_dirplane(info, 0);
	else if (info->spawn == 'S')
		init_dirplane(info, 1);
	else if (info->spawn == 'W')
		init_dirplane(info, 2);
	else if (info->spawn == 'E')
		init_dirplane(info, 3);
}

void	init_raycasting_info(t_info *info, t_ray *r, int x)
{
	r->cur_x = (int)info->pos_x;
	r->cur_y = (int)info->pos_y;
	r->cam_x = 2 * x / (double)(LARGEUR) - 1;
	r->raydir_x = info->p.dir_x + info->p.plane_x * r->cam_x;
	r->raydir_y = info->p.dir_y + info->p.plane_y * r->cam_x;
	r->delta_dist_x = fabs(1 / r->raydir_x);
	r->delta_dist_y = fabs(1 / r->raydir_y);
}

void	init_side_dist(t_info *info, t_ray *r)
{
	if (r->raydir_x > 0)
	{
		r->step_x = 1;
		r->side_dist_x = (r->cur_x + 1 - info->pos_x) * r->delta_dist_x;
	}	
	else
	{
		r->step_x = -1;
		r->side_dist_x = (info->pos_x - r->cur_x) * r->delta_dist_x;
	}
	if (r->raydir_y > 0)
	{
		r->step_y = 1;
		r->side_dist_y = (r->cur_y + 1 - info->pos_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = -1;
		r->side_dist_y = (info->pos_y - r->cur_y) * r->delta_dist_y;
	}
}