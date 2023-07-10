/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:04:23 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/22 16:04:19 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	t;

	t = (char) c;
	i = 0;
	if (!n)
		return (0);
	str = (char *) s;
	while (i < n)
	{
		if (str[i] == t)
			return (str + i);
		else
			i++;
	}
	if (t == 0)
		return (str + i);
	return (0);
}
