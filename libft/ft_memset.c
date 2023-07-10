/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:48:10 by jlaurent          #+#    #+#             */
/*   Updated: 2021/10/16 15:25:50 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	i;
	char			*s;

	i = 0;
	s = str;
	while (i < n)
	{
		s[i++] = c;
	}
	return (str);
}
/*
int main()
{
	char str[50] = "test123test456test789";
	printf("\navant memset(): %s\n", str);

	ft_memset(str + 5, '.', 8*sizeof(char));
	printf("apres memset(): %s", str);
    return 0;
}*/
