/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocktextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:09:21 by jlaurent          #+#    #+#             */
/*   Updated: 2023/01/20 18:09:21 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int setinfo(char *str, t_info *info, int o)
{
    int i;

    i = 0;
    if (findoc(str, '.') == 1 || findoc(str, '/') == 1 || ft_strlen(str) <= 2)
        return (1);
    while (str[i] != '.')
        i++;
    if (info->found[o] == 1)
        return (1);
    info->pc[o] = ft_substr(str, i, ft_strlen(str) - i);
    info->found[o] = 1;
    printf("%s\n", info->pc[o]);
    return (0);
}

int setcolor(char *str, t_info *info, int o)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (str[i] < '0' || str[i] > '9')
        i++;
    if (info->found[o] == 1 || verifycline(str) == 1)
        return (1);
    if (o == 4)
    {
        while (n < 3)
            info->f[n++] = ft_atoi(ft_split(ft_substr(str, i, ft_strlen(str) - i), ',')[n]);
        info->color = 1;
    }
    if (o == 5)
    {
        while (n < 3)
            info->c[n++] = ft_atoi(ft_split(ft_substr(str, i, ft_strlen(str) - i), ',')[n]);
        info->full = 1;
    }
    return (0);
}


int checkcolor(t_info *info)
{
    int n;

    n = 0;
    while (n < 3)
    {
        if (info->c[n] < 0 || info->c[n] > 255)
            return (1);
        if (info->f[n] < 0 || info->f[n] > 255)
            return (1);
        n++;
    }
    return (0);
}

int infoerror(char *str, t_info *info)
{
    int ret;

    ret = 1;
//    if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
//			&& str[0] != 'F' && str[0] != 'C' && str[0] > 65 && str[0] < 122)
  //      ret = 1;
    if (str[0] == 'N' && str[1] == 'O')
        ret = beforeinfo(str, 2, 1);
    else if (str[0] == 'S' && str[1] == 'O')
        ret = beforeinfo(str, 2, 1);
    else if (str[0] == 'W' && str[1] == 'E')
        ret = beforeinfo(str, 2, 1);
    else if (str[0] == 'E' && str[1] == 'A')
        ret = beforeinfo(str, 2, 1);
    else if (str[0] == 'F')
        ret = beforeinfo(str, 1, 2);
    else if (str[0] == 'C')
        ret = beforeinfo(str, 1, 2);
    else if (info->full == 1 && info->color == 1)
        ret = 0;
    if (info->full == 1 && info->color == 1)
        ret = checkcolor(info);
    return (ret);
}

int stockinfo(char *str, t_info *info)
{
    int ret;

    if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
        ret = setinfo(str, info, 0);
    else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
        ret = setinfo(str, info, 1);
    else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
        ret = setinfo(str, info, 2);
    else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
        ret = setinfo(str, info, 3);
    else if (str[0] == 'F' && str[1] == ' ')
        ret = setcolor(str, info, 4);
    else if (str[0] == 'C' && str[1] == ' ')
        ret = setcolor(str, info, 5);
//    else if (info->full == 1)
//        ret = tomap(str, info);
    if (ret == 1)
        return (ret);
    ret = infoerror(str, info);
    return (ret);    
}