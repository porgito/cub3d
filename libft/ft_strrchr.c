/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:40:33 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/22 16:01:25 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char) c;
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == t)
			return ((char *) s + i);
		else
			i--;
	}
	if (t == 0)
		return ((char *) s + i);
	return (0);
}
/*
int	main()
{
	char	s[] = "salut";
	int		c = 't' + 257;
	printf("%s", strrchr(s, c));
}*/
