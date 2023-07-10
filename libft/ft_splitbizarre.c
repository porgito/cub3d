/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:07:52 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/22 17:39:53 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = malloc(10000);
	if (!s || !c)
		return (NULL);
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
		{
			i++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			tab[j] = malloc(1000);
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int	main()
{
	char	s[] = " salut bonjour ciao ";
	char	c = ' ';
	char	**tab;
	int	i = 0;
	tab = ft_split(s, c);
	while (tab[i])
		printf("%s", tab[i++]);
}
