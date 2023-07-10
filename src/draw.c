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

int		color_column(t_info *info)
{
	int j;
	int i;

	j = -1;
	info->ray.drawend = LARGEUR - info->ray.drawstart;
	i = info->ray.drawend;
	while (++j < info->ray.drawstart)
		info->data.addr[j * info->data.line_length / 4 +
			info->ray.x] = info->c;
	if (j <= info->ray.drawend)
		draw_texture(info, info->ray.x, j);
	j = i;
	while (++j < LARGEUR)
		info->data.addr[j * info->data.line_length / 4 +
			info->ray.x] = info->f;
	return (0);
}

void	draw_texture(t_info *info, int x, int y)
{
	y = info->ray.drawstart - 1;
    init_texture(info);
	info->t.step = 1.0 * info->texture[0].height / info->ray.lineheight;
	info->t.texx = (int)(info->t.wallx * (double)info->texture
			[info->t.texdir].width);
	if (info->ray.side == 0 && info->ray.raydirx > 0)
		info->t.texx = info->texture[info->t.texdir].width -
			info->t.texx - 1;
	if (info->ray.side == 1 && info->ray.raydiry < 0)
		info->t.texx = info->texture[info->t.texdir].width -
			info->t.texx - 1;
	info->t.texpos = (info->ray.drawstart - LARGEUR / 2 +
			info->ray.lineheight / 2) * info->t.step;
	while (++y <= info->ray.drawend)
	{
		info->t.texy = (int)info->t.texpos &
			(info->texture[info->t.texdir].height - 1);
		info->t.texpos += info->t.step;
		if (y < LARGEUR && x < HAUTEUR)
			info->data.addr[y * info->data.line_length / 4 + x] =
				info->texture[info->t.texdir].addr[info->t.texy *
					info->texture[info->t.texdir].line_length /
					4 + info->t.texx];
	}
}

void	draw_sprite(t_info *info, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < info->s.drawendy)
	{
		d = (y) * 256 - LARGEUR * 128 + info->s.spriteheight * 128;
		texy = ((d * info->texture[4].height) / info->s.spriteheight) / 256;
		if (info->texture[4].addr[texy * info->texture[4].line_length / 4 +
				texx] != -16777216)
		{
			info->data.addr[y * info->data.line_length / 4 + stripe] =
				info->texture[4].addr[texy * info->texture[4].line_length /
				4 + texx];
		}
		y++;
	}
}