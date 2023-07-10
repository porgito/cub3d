/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:07 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/22 16:02:41 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t)
			return ((char *)s + i);
		else
			i++;
	}
	if (t == 0)
		return ((char *)s + i);
	return (0);
}
/*
int	main()
{
	char	str1[] = "salut"
}*/
