/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:39:46 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/16 15:22:23 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	char	*source;

	source = (char *) src;
	c = 0;
	if (dstsize == 0)
		return (ft_len(source));
	while (c < dstsize - 1 && source[c] != '\0')
	{
		dst[c] = source[c];
		c++;
	}
	if (c < dstsize)
		dst[c] = '\0';
	return (ft_len(source));
}
/*
int	main()
{
	char	str1[] = "test";
	char	str2[] = "salut";

	strlcpy(str2, str1, 4);
	puts(str2);
}*/
