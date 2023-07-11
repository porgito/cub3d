/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:41:00 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/01 13:41:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_info *info)
{
	if (info->mapi[(int)(info->pos_y)] \
		[(int)(info->pos_x + info->p.dir_x * SPEED)] != '1')
		info->pos_x += info->p.dir_x * SPEED;
	if (info->mapi[(int)(info->pos_y \
		+ info->p.dir_y * SPEED)][(int)(info->pos_x)] != '1')
		info->pos_y += info->p.dir_y * SPEED;
}

void	move_down(t_info *info)
{
	if (info->mapi[(int)(info->pos_y)] \
		[(int)(info->pos_x - info->p.dir_x * SPEED)] != '1')
		info->pos_x -= info->p.dir_x * SPEED;
	if (info->mapi[(int)(info->pos_y \
		- info->p.dir_y * SPEED)][(int)(info->pos_x)] != '1')
		info->pos_y -= info->p.dir_y * SPEED;
}

void	move_left(t_info *info)
{
	if (info->mapi[(int)(info->pos_y)]
		[(int)(info->pos_x + info->p.plane_x * SPEED)] != '1')
		info->pos_x += info->p.plane_x * SPEED;
	if (info->mapi[(int)(info->pos_y \
		+ info->p.plane_y * SPEED)][(int)(info->pos_x)] != '1')
		info->pos_y += info->p.plane_y * SPEED;
}

void	move_right(t_info *info)
{
	if (info->mapi[(int)(info->pos_y)] \
		[(int)(info->pos_x - info->p.plane_x * SPEED)] != '1')
		info->pos_x -= info->p.plane_x * SPEED;
	if (info->mapi[(int)(info->pos_y \
		- info->p.plane_y * SPEED)][(int)(info->pos_x)] != '1')
			info->pos_y -= info->p.plane_y * SPEED;
}

void	rotate_left(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->p.dir_x;
	info->p.dir_x = info->p.dir_x \
		* cos(info->angle) + info->p.dir_y * sin(info->angle);
	info->p.dir_y = -olddir_x \
		* sin(info->angle) + info->p.dir_y * cos(info->angle);
	oldplane_x = info->p.plane_x;
	info->p.plane_x = info->p.plane_x \
		* cos(info->angle) + info->p.plane_y * sin(info->angle);
	info->p.plane_y = -oldplane_x \
		* sin(info->angle) + info->p.plane_y * cos(info->angle);
}

void	rotate_right(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->p.dir_x;
	info->p.dir_x = info->p.dir_x \
		* cos(info->angle) - info->p.dir_y * sin(info->angle);
	info->p.dir_y = olddir_x \
		* sin(info->angle) + info->p.dir_y * cos(info->angle);
	oldplane_x = info->p.plane_x;
	info->p.plane_x = info->p.plane_x
		* cos(info->angle) - info->p.plane_y * sin(info->angle);
	info->p.plane_y = oldplane_x
		* sin(info->angle) + info->p.plane_y * cos(info->angle);
}