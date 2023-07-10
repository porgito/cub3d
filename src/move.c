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

void	forward_back(t_info *info)
{
	if (info->data.forward == 1)
	{
		if (info->mapi[(int)(info->ray.posx + (info->ray.dirx * info->
						ray.movespeed * 2))][(int)info->ray.posy] == '0')
			info->ray.posx += info->ray.dirx * info->ray.movespeed;
		if (info->mapi[(int)(info->ray.posx)][(int)(info->ray.posy +
					(info->ray.diry * info->ray.movespeed * 2))] == '0')
			info->ray.posy += info->ray.diry * info->ray.movespeed;
	}
	if (info->data.back == 1)
	{
		if (info->mapi[(int)(info->ray.posx - (info->ray.dirx * info->
						ray.movespeed * 2))][(int)(info->ray.posy)] == '0')
			info->ray.posx -= info->ray.dirx * info->ray.movespeed;
		if (info->mapi[(int)(info->ray.posx)][(int)(info->ray.posy -
					(info->ray.diry * info->ray.movespeed * 2))] == '0')
			info->ray.posy -= info->ray.diry * info->ray.movespeed;
	}
}

void	left_right(t_info *info)
{
	if (info->data.right == 1)
	{
		if (info->mapi[(int)(info->ray.posx + info->ray.diry *
					(info->ray.movespeed * 2))][(int)info->ray.posy] == '0')
			info->ray.posx += info->ray.diry * info->ray.movespeed;
		if (info->mapi[(int)info->ray.posx][(int)(info->ray.posy -
					info->ray.dirx *
					(info->ray.movespeed * 2))] == '0')
			info->ray.posy -= info->ray.dirx * info->ray.movespeed;
	}
	if (info->data.left == 1)
	{
		if (info->mapi[(int)(info->ray.posx - info->ray.diry *
					(info->ray.movespeed * 2))][(int)info->ray.posy] == '0')
			info->ray.posx -= info->ray.diry * info->ray.movespeed;
		if (info->mapi[(int)info->ray.posx][(int)(info->ray.posy +
					info->ray.dirx *
					(info->ray.movespeed * 2))] == '0')
			info->ray.posy += info->ray.dirx * info->ray.movespeed;
	}
}

void	rotate_right_left(t_info *info)
{
	double oldplanx;
	double olddirx;

	oldplanx = info->ray.planx;
	olddirx = info->ray.dirx;
	if (info->data.rotate_right == 1)
	{
		info->ray.dirx = info->ray.dirx * cos(-info->ray.rotspeed / 2) -
			info->ray.diry * sin(-info->ray.rotspeed / 2);
		info->ray.diry = olddirx * sin(-info->ray.rotspeed / 2) +
			info->ray.diry * cos(-info->ray.rotspeed / 2);
		info->ray.planx = info->ray.planx * cos(-info->ray.rotspeed / 2)
			- info->ray.plany * sin(-info->ray.rotspeed / 2);
		info->ray.plany = oldplanx * sin(-info->ray.rotspeed / 2) +
			info->ray.plany * cos(-info->ray.rotspeed / 2);
	}
	rotate_left(info, olddirx);
}

void	rotate_left(t_info *info, double olddirx)
{
	double oldplanex;

	if (info->data.rotate_left == 1)
	{
		olddirx = info->ray.dirx;
		oldplanex = info->ray.planx;
		info->ray.dirx = info->ray.dirx * cos(info->ray.rotspeed / 2) -
			info->ray.diry * sin(info->ray.rotspeed / 2);
		info->ray.diry = olddirx * sin(info->ray.rotspeed / 2) + info->
			ray.diry * cos(info->ray.rotspeed / 2);
		info->ray.planx = info->ray.planx * cos(info->ray.rotspeed / 2) -
			info->ray.plany * sin(info->ray.rotspeed / 2);
		info->ray.plany = oldplanex * sin(info->ray.rotspeed / 2) +
			info->ray.plany * cos(info->ray.rotspeed / 2);
	}
}