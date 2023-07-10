/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:02:44 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/09 14:02:44 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	dist_order2(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->s.nbspr)
	{
		info->s.order[i] = i;
		info->s.dist[i] = ((info->ray.posx - info->sxy[i].x) *
				(info->ray.posx - info->sxy[i].x) + (info->ray.posy -
					info->sxy[i].y) * (info->ray.posy - info->sxy[i].y));
	}
}

void	dist_order(t_info *info)
{
	int		i;
	int		j;
	double	tmp;

	dist_order2(info);
	i = -1;
	while (++i < info->s.nbspr)
	{
		j = -1;
		while (++j < info->s.nbspr - 1)
		{
			if (info->s.dist[j] < info->s.dist[j + 1])
			{
				tmp = info->s.dist[j];
				info->s.dist[j] = info->s.dist[j + 1];
				info->s.dist[j + 1] = tmp;
				tmp = info->s.order[j];
				info->s.order[j] = info->s.order[j + 1];
				info->s.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	calculs(t_info *info, int i)
{
	info->s.spritex = info->sxy[info->s.order[i]].x - info->ray.posx;
	info->s.spritey = info->sxy[info->s.order[i]].y - info->ray.posy;
	info->s.invdet = 1.0 / (info->ray.planx * info->ray.diry -
			info->ray.dirx * info->ray.plany);
	info->s.transformx = info->s.invdet * (info->ray.diry *
			info->s.spritex - info->ray.dirx * info->s.spritey);
	info->s.transformy = info->s.invdet * (-info->ray.plany *
			info->s.spritex + info->ray.planx * info->s.spritey);
	info->s.spritescreenx = (int)((HAUTEUR / 2) * (1 + info->s.transformx
				/ info->s.transformy));
	info->s.spriteheight = abs((int)(LARGEUR / (info->s.transformy)));
	info->s.drawstarty = -info->s.spriteheight / 2 + LARGEUR / 2;
	if (info->s.drawstarty < 0)
		info->s.drawstarty = 0;
	info->s.drawendy = info->s.spriteheight / 2 + LARGEUR / 2;
	if (info->s.drawendy >= LARGEUR)
		info->s.drawendy = LARGEUR;
	info->s.spritewidth = abs((int)(LARGEUR / (info->s.transformy)));
	info->s.drawstartx = -info->s.spritewidth / 2 + info->s.spritescreenx;
	if (info->s.drawstartx < 0)
		info->s.drawstartx = 0;
	info->s.drawendx = info->s.spritewidth / 2 + info->s.spritescreenx;
	if (info->s.drawendx >= HAUTEUR)
		info->s.drawendx = HAUTEUR;
}



/*void	sprite(t_info *info)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = -1;
	dist_order(info);
	while (++i < info->s.nbspr)
	{
		calculs(info, i);
		stripe = info->s.drawstartx;
		while (stripe < info->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-info->s.spritewidth / 2 +
							info->s.spritescreenx)) * info->texture[4].width
					/ info->s.spritewidth) / 256;
			if (info->s.transformy > 0 && stripe >= 0 && stripe < HAUTEUR
					&& info->s.transformy < info->s.zbuffer[stripe])
			{
				y = info->s.drawstarty;
				draw_sprite(info, y, texx, stripe);
			}
			stripe++;
		}
	}
}*/