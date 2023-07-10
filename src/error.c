/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:02:44 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/07 17:02:44 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error2(t_info *info)
{
	free(info->found);
    free(info->f);
    free(info->c);
	if (info->mapi)
		free(info->mapi);
    if (info->pc)
        free(info->pc);
	if (info->s.order)
		free(info->s.order);
	if (info->s.dist)
		free(info->s.dist);
	if (info->sxy)
		free(info->sxy);
	if (info->s.zbuffer)
		free(info->s.zbuffer);
	ft_exit(info);
}

void	error(t_info *info, char *str)
{
	int i;

	i = -1;
	printf("Error: %s\n", str);
    if (info->pc)
	{
		while (++i < 3)
			free(info->pc[i]);
	}
    i = -1;
	if (info->mapi)
	{
		while (++i < info->line)
			free(info->mapi[i]);
	}
	error2(info);
}

int		ft_exit(t_info *info)
{
	if (info->data.img)
		mlx_destroy_image(info->data.mlx_ptr, info->data.img);
	if (info->texture[0].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[0].img);
	if (info->texture[1].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[1].img);
	if (info->texture[2].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[2].img);
	if (info->texture[3].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[3].img);
	if (info->texture[4].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[4].img);
	if (info->data.mlx_win)
		mlx_destroy_window(info->data.mlx_ptr, info->data.mlx_win);
	exit(0);
}

void	verify_errors(t_info *info)
{
	if (info->spawn == '0')
		error(info, "NO SPAWN");
	if (info->toomuchspawn == 1)
		error(info, "TOO MUCH SPAWN");
}