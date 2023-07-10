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

void	init_dir(t_info *info)
{
	if (info->spawn == 'N')
		info->ray.dirx = -1;
	if (info->spawn == 'S')
		info->ray.dirx = 1;
	if (info->spawn == 'E')
		info->ray.diry = 1;
	if (info->spawn == 'W')
		info->ray.diry = -1;
	if (info->spawn == 'N')
		info->ray.plany = 0.66;
	if (info->spawn == 'S')
		info->ray.plany = -0.66;
	if (info->spawn == 'E')
		info->ray.planx = 0.66;
	if (info->spawn == 'W')
		info->ray.planx = -0.66;
}

void	init_more(t_info *info)
{
	if (info->ray.raydiry == 0)
		info->ray.deltadistx = 0;
	else if (info->ray.raydirx == 0)
		info->ray.deltadistx = 1;
	else
		info->ray.deltadistx = sqrt(1 + (info->ray.raydiry
			* info->ray.raydiry) / (info->ray.raydirx *
			info->ray.raydirx));
	if (info->ray.raydirx == 0)
		info->ray.deltadisty = 0;
	else if (info->ray.raydiry == 0)
		info->ray.deltadisty = 1;
	else
		info->ray.deltadisty = sqrt(1 + (info->ray.raydirx *
			info->ray.raydirx) / (info->ray.raydiry *
			info->ray.raydiry));
}