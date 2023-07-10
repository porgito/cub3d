/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:27:59 by jlaurent          #+#    #+#             */
/*   Updated: 2023/01/20 19:27:59 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//CHERCHE SI LE CHAR OC APPARAIT DANS LA STRING//
int findoc(char *str, char oc)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == oc)
            return (0);
        i++;
    }
    return (1);
}


//RETOURNE LE NOMBRE DE LIGNE DE LA MAP//
unsigned int    countnl(char *map)
{
    int     fd;
    char    *str;
    int     nl;

    fd = open(map, O_RDONLY);
    str = "(null)";
    nl = 0;
    while (str != NULL)
    {
        str = get_next_line(fd);
        nl++;
        free(str);
    }
    close(fd);
    printf("NEWLINE: %d\n", nl);
    return (nl);
}


//REGARDE SI IL Y A UN CHARACTERE ENTRE L'IDENTIFIANT ET SON INFORMATION//
//p EST L'INDEX DANS LA STRING ET what LE TYPE D'ELEMENT À VERIFIER// 
//what = 1 POUR LES POINTS CARDINAUX ET what = 2 POUR LES COULEURS//
int beforeinfo(char *str, int p, int what)
{
    if (what == 1)
    {
        while (str[p] != '.')
        {
            if (str[p] != ' ' && str[p] != '\t')
                return (1);
            p++;
        }
    }
    if (what == 2)
    {
        while (str[p] < '0' || str[p] > '9')
        {
            if (str[p] != ' ' && str[p] != '\t')
                return (1);
            p++;
        }
    }
    return (0);
}

int verifycline(char *str)
{
    int i;
    int comma;
    int ret;

    i = 2;
    comma = 0;
    ret = 0;
    while (i < ft_strlen(str) - 2)
    {
        if (str[i] == ',')
            comma++;
        if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != '\n')
            ret = 1;
        i++;
    }
    if (comma != 2)
        return (1);
    return (ret);
}