/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:07:52 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/22 19:36:11 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word(char const *s, int i, char c)
{
	int	n;

	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c)
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

int	count(char const *s, int i, char c)
{
	int	l;

	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		l++;
		i++;
	}
	return (l);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(((word(s, i, c) + 1) * sizeof(char *)));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != c)
		{
			tab[j] = ft_substr(s, i, count(s, i, c));
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	if (s[ft_strlen(s) - 1] == c)
		j = j - 1;
	tab[j] = NULL;
	return (tab);
}
/*
int	main()
{
	char	s[] = " salut bonjour ciao ";
	char	c = ' ';
	char	**tab;
	int	i = 0;
	tab = ft_split(s, c);
	while (tab[i])
		printf("%s", tab[i++]);
}*/
