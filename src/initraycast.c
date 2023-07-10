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

void	init2(t_info *info)
{
	if (!(info->s.zbuffer = (double *)malloc(sizeof(double) * HAUTEUR)))
		exit(0);
	info->data.forward = 0;
	info->data.back = 0;
	info->data.left = 0;
	info->data.right = 0;
	info->data.rotate_right = 0;
	info->data.rotate_left = 0;
	info->ray.posx = (double)info->x + 0.5;
	info->ray.posy = (double)info->y + 0.5;
	info->ray.dirx = 0;
	info->ray.diry = 0;
	info->ray.planx = 0;
	info->ray.plany = 0;

	init_dir(info);
}

void	init3(t_info *info)
{
	info->ray.hit = 0;
	info->ray.perpwalldist = 0;
	info->ray.camerax = 2 * info->ray.x / (double)HAUTEUR - 1;
	info->ray.raydirx = info->ray.dirx + info->ray.planx * \
						info->ray.camerax;
	info->ray.raydiry = info->ray.diry + info->ray.plany * \
						info->ray.camerax;
	info->ray.mapx = (int)info->ray.posx;
	info->ray.mapy = (int)info->ray.posy;
	info->ray.movespeed = 0.1;
	info->ray.rotspeed = 0.033 * 1.8;
	init_more(info);
}

void	init_texture(t_info *info)
{
	if (info->ray.side == 0 && info->ray.raydirx < 0)
		info->t.texdir = 0;
	if (info->ray.side == 0 && info->ray.raydirx >= 0)
		info->t.texdir = 1;
	if (info->ray.side == 1 && info->ray.raydiry < 0)
		info->t.texdir = 2;
	if (info->ray.side == 1 && info->ray.raydiry >= 0)
		info->t.texdir = 3;
	if (info->ray.side == 0)
		info->t.wallx = info->ray.posy + info->ray.perpwalldist \
						* info->ray.raydiry;
	else
		info->t.wallx = info->ray.posx + info->ray.perpwalldist \
						* info->ray.raydirx;
	info->t.wallx -= floor((info->t.wallx));
}

void	init_sprite(t_info *info)
{
	int i;
	int j;

	i = -1;
	info->s.nbspr = 0;
	verify_errors(info);
	while (++i < info->line)
	{
		j = -1;
		while (++j < info->col)
		{
			if (info->mapi[i][j] == '2')
				info->s.nbspr += 1;
		}
	}
	if (!(info->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * info->s.nbspr)))
		error(info, "Malloc sxy*");
	if (!(info->s.order = (int *)malloc(sizeof(int) * info->s.nbspr)))
		error(info, "Malloc s.order*");
	if (!(info->s.dist = (double *)malloc(sizeof(double) * info->s.nbspr)))
		error(info, "Malloc s.dist*");
	init_sprite2(info, 0, 0, 0);
	init_mlx(info);
}

void	init_sprite2(t_info *info, int i, int j, int v)
{
	i = i - 1;
	while (++i < info->line)
	{
		j = -1;
		while (++j < info->col)
		{
			if (info->mapi[i][j] == '2')
			{
				info->sxy[v].x = (double)i + 0.5;
				info->sxy[v].y = (double)j + 0.5;
				v++;
			}
		}
	}
}