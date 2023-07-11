/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:15:56 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/06 23:15:56 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	adjust_pos_range(t_info *info)
{
	if (info->mapi[(int)(info->pos_y + 0.01)][(int)info->pos_x] == '1')
		info->pos_y -= 0.01;
	else if (info->mapi[(int)(info->pos_y - 0.01)][(int)info->pos_x] == '1')
		info->pos_y += 0.01;
	else if (info->mapi[(int)info->pos_y][(int)(info->pos_x + 0.01)] == '1')
		info->pos_x -= 0.01;
	else if (info->mapi[(int)info->pos_y][(int)(info->pos_x - 0.01)] == '1')
		info->pos_x += 0.01;
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	else if (keycode == FORWARD)
		move_up(info);
	else if (keycode == BACK)
		move_down(info);
	else if (keycode == RIGHT)
		move_left(info);
	else if (keycode == LEFT)
		move_right(info);
	else if (keycode == ROTATE_L)
		rotate_left(info);
	else if (keycode == ROTATE_R)
		rotate_right(info);
	adjust_pos_range(info);
	return (0);
}