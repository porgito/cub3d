/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:56:39 by jlaurent          #+#    #+#             */
/*   Updated: 2023/06/26 15:56:39 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int checkex(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);   
}

int checkwalls(t_info *info)
{
	int i;

	i = 0;
	while (i < info->line)
	{
		if (info->mapi[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < info->line)
	{
		if (info->mapi[i][info->col - 1] != '1')
			return (1);
		i++;
	}
	if (checkex(info->mapi[0]) == 1)
		return (1);
	if (checkex(info->mapi[info->line - 1]) == 1)
		return (1);
	return (0);
}

int parsemap(char *map, t_info *info)
{
    char            *str;
    int             fd;
    unsigned int    n;

    n = info->nl;
    fd = open(map, O_RDONLY);
    while (n - 1 >= info->getmap)
    {
        str = get_next_line(fd);
        n--;
        free(str);
    }
    while (n > 1)
    {
        str = get_next_line(fd);
        if (stockmap(str, info) == 1)
            return (1);
        n--;
        free(str);
    }
    close(fd);
    if (checkwalls(info) == 1)
        error(info, "WALL ERROR");
    return (0);
}

void    checkline(t_info *info, char *str, int j)
{
    int c;

    c = 0;
    if (str[j] == '\n' && str[j - 1] != '1')
        error(info, "NO WALL AT END OF LINE");
    if (str[j] != '1' && str[j] != '0' && str[j] != 'W' && str[j] != 'S' &&
        str[j] != 'N' && str[j] != 'E' && str[j] != ' ' && str[j] != '\n')
    {
        printf("-----%c----%d\n", str[j], j);
        error(info, "MAP ERROR");
    }
    j = 0;
}

int    stockmap(char *str, t_info *info)
{
    static int i = 0;
    int        j;
    int        s;

    j = 0;
    s = 0;
    info->mapi[i] = (char *)malloc(info->col * sizeof(char));
    while (str[j] != '\0')
    {
        checkline(info, str, j);
        if (checkspawn(str[j], i, j, info) == 1)
            info->mapi[i][j] = '0';
        else if (str[j] == ' ')
            info->mapi[i][j] = '1';
        else if (str[j] == '\n')
            break;
        else
            info->mapi[i][j] = str[j];
        if (str[j] == '1')
            s = 1;
        j++;
    }
	while (j <= (info->col - 1))
	{
		info->mapi[i][j] = '1';
		j++;
	}
    if (s == 0)
        error(info, "NO WALL ON LINE");
    info->mapi[i][j] = '\0';
    i++;
    return(0); 
}