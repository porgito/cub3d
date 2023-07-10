/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:09 by jlaurent          #+#    #+#             */
/*   Updated: 2023/01/20 17:57:09 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    initinfo(t_info *info)
{
    info->pc = malloc(4 * sizeof(char *));
    info->found = malloc(6 * sizeof(int));
    info->f = malloc(3 * sizeof(int));
    info->c = malloc(3 * sizeof(int));

    info->found[0] = 0;
    info->found[1] = 0;
    info->found[2] = 0;
    info->found[3] = 0;
    info->found[4] = 0;
    info->found[5] = 0;
    info->f[0] = -1;
    info->f[1] = -1;
    info->f[2] = -1;
    info->c[0] = -1;
    info->c[1] = -1;
    info->c[2] = -1;
    info->full = 0;
    info->color = 0;
    info->ret = 0;
    info->findmap = 0;
    info->getmap = 0;
    initinfo2(info);
}

void    initinfo2(t_info *info)
{
    info->spawn = '0';
    info->toomuchspawn = 0;
    info->mapi = NULL;
	info->s.order = NULL;
	info->s.dist = NULL;
	info->s.zbuffer = NULL;
	info->sxy = NULL;
}