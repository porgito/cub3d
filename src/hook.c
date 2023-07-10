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

int		key_press(int keycode, t_info *info)
{
	if (keycode == FORWARD)
		info->data.forward = 1;
	else if (keycode == BACK)
		info->data.back = 1;
	else if (keycode == LEFT)
		info->data.left = 1;
	else if (keycode == RIGHT)
		info->data.right = 1;
	else if (keycode == ROTATE_L)
		info->data.rotate_left = 1;
	else if (keycode == ROTATE_R)
		info->data.rotate_right = 1;
	return (1);
}

int		key_release(int keycode, t_info *info)
{
	if (keycode == FORWARD)
		info->data.forward = 0;
	else if (keycode == BACK)
		info->data.back = 0;
	else if (keycode == LEFT)
		info->data.left = 0;
	else if (keycode == RIGHT)
		info->data.right = 0;
	else if (keycode == ROTATE_L)
		info->data.rotate_left = 0;
	else if (keycode == ROTATE_R)
		info->data.rotate_right = 0;
	return (1);
}