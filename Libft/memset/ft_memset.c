/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 10:51:28 by dshofer           #+#    #+#             */
/*   Updated: 2026/10/08 15:25:42 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	ft_memset(void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (*a);
}
/*
 int main(void)
{
	int	c = 7;
	size_t	n = 3;
	char buf[10];

	for (int i = 0; i < n+1; i++)
	{
		printf("%d\n",buf[i]);
	}
	ft_memset(buf,c,n);
	for (int i = 0; i < n+1; i++)
        {
		printf("%d\n", buf[i]);
	}
}
*/
