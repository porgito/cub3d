/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:03:53 by jlaurent          #+#    #+#             */
/*   Updated: 2023/01/19 19:03:53 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int tomap(char *str, t_info *info, int n)
{
    int i;

    i = 0;
    if (info->full == 0)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] == '1')
        {
            info->findmap = 1;
            if (info->getmap < n)
                info->getmap = n;
            break;
        }
        if (str[i] != ' ' && str[i] != '1' && str[i] != '\n' && str[i] != '\0')
            return (1);
        i++;
    }
}

void    newtest(char *str, t_info *info)
{
    int i;
    static int  sline = 0;
	static int	scol = 0;

	i = 0;
    if (info->findmap == 1)
    {
		if ((i = ft_strlen(str)) > scol)
			scol = i;
		sline = sline + 1;
        printf("NB: %d, SL: %d\n %s\n", sline, scol, str);
    }
	info->line = sline;
	info->col = scol;
}

void    checkmap(char *map, t_info *info)
{
    char            *str;
    int             fd;
    unsigned int    n;

    info->nl = countnl(map);
    n = info->nl;
    fd = open(map, O_RDONLY);
    while (n - 1 > 0)
    {
        str = get_next_line(fd);
        if (tomap(str, info, n) == 1)
            error(info, "NO MAP FOUND");
        if (stockinfo(str, info) == 1)
            error(info, "PARSING FAILED");
//        printf("%d : %s", nl, str);
        newtest(str, info);
        n--;
        free(str);
    }
    close(fd);
}

int checkspawn(char pos, int i, int j, t_info *info)
{
    if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
    {
        if (info->spawn != '0')
            info->toomuchspawn = 1;
        info->spawn = pos;
        info->x = i;
        info->y = j;
        return (1);
    }
    return (0);
}