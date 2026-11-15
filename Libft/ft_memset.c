/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 10:51:28 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/14 14:57:12 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
}
