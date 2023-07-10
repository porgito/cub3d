/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:34:46 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/16 15:22:09 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = ft_strlen(dest);
	j = 0;
	c = i;
	if (destsize == 0)
		return (ft_strlen((char *) src));
	while (src[j] != '\0' && i < destsize - 1)
		dest[i++] = src[j++];
	if (destsize != 0 && destsize >= c)
		dest[i] = '\0';
	if (destsize < (size_t) ft_strlen(dest))
		return (ft_strlen((char *) src) + destsize);
	else
		return (ft_strlen((char *) src) + c);
}
/*
int	main()
{
	char	dest[20] = "test";
	char	src[] = "123456";

	puts(dest);
	strlcat(dest, src, 25);
	puts(dest);
}*/
