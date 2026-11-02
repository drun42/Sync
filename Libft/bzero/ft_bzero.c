/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:21:27 by dshofer           #+#    #+#             */
/*   Updated: 2026/10/08 15:27:13 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	size_t	n = 3;
	char buf[10];

	for (int i = 0; i < n+1; i++)
	{
		printf("%d\n",buf[i]);
	}
	ft_bzero(buf, n);
	for (int i = 0; i < n+1; i++)
	{
		printf("%d\n", buf[i]);
	}
}
*/
