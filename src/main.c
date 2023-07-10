/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:48:48 by jlaurent          #+#    #+#             */
/*   Updated: 2023/01/19 16:48:48 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int checkext(t_info *info, char *file)
{
    int len;

    len = ft_strlen(file);
    if (file[len - 4] != '.')
        error(info, "MAP DOESN'T HAVE .cub EXTENSION");
    else if (file[len - 3] != 'c')
        error(info, "MAP DOESN'T HAVE .cub EXTENSION");
    else if (file[len - 2] != 'u')
        error(info, "MAP DOESN'T HAVE .cub EXTENSION");
    else if (file[len - 1] != 'b')
        error(info, "MAP DOESN'T HAVE .cub EXTENSION");
}

char    *adddir(char *file)
{
    char    *dir;

    dir = "./map/";
    return (ft_strjoin(dir, file));
}

void    checkfile(t_info *info, char *file)
{
    if (open(file, O_RDONLY) == -1)
        error(info, "IMPOSSIBLE TO OPEN FILE");
    checkext(info, file);
}

void    checkarg(t_info *info, int ac, char **av)
{
    if (ac != 2)
        error(info, "A FILE NAME FOR THE MAP IS REQUIRED");
    checkfile(info, adddir(av[1]));
}

int main(int ac, char **av)
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    if (!info)
        return (1);
    initinfo(info);
    checkarg(info, ac, av);
    checkmap(adddir(av[1]), info);
    info->mapi = (char **)malloc(info->line * sizeof(char *));
    parsemap(adddir(av[1]), info);
    init_mlx(info);
    printf("C %d,%d,%d\nF %d,%d,%d\n", info->c[0], info->c[1], info->c[2], info->f[0], info->f[1], info->f[2]);
    for (int i = 0; i < info->line; i++)
    {
        printf("%s\n", info->mapi[i]);
    }
    
    printf("\nx spawn: %d, y spawn: %d\n", info->x, info->y);
    printf("line: %d, col: %d, n: %d\n", info->line, info->col, info->getmap);
}