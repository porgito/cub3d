/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:15:00 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/19 18:55:49 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i] && ft_strchr(set, s1[ft_strlen(s1) - j - 1]))
		j++;
	if (i == ft_strlen(s1) + 1)
		return (malloc(1));
	str = ft_substr(s1, i, ft_strlen(s1) - j - i);
	return (str);
}
/*
int	main()
{
	char	s[] = "lllllllllllsalllutalllaaaal";
	char	set[] = "la";
	char	*str;
	str = ft_strtrim(s, set);
	puts(str);
}*/
