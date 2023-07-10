/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:43:26 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/16 15:20:10 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long		i;
	int					j;

	i = 0;
	j = len;
	if (dst < src)
	{
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	else if (dst > src)
	{
		while (j > 0)
		{
			*(char *)(dst + j - 1) = *(char *)(src + j - 1);
			j--;
		}
	}
	return (dst);
}
/*
int	main()
{
	char str1[] = "ae";
	char str2[] = "1237";
	printf("str1 avant\n");
	puts (str1);

	memmove(str1, str2, 3);

	puts("str1 apres");
	puts(str1);
}*/
