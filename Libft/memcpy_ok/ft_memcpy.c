/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 19:43:46 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/13 17:03:33 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
//#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	const char	*s;
	long unsigned int	i;

	i = 0;
	d = (char *)dest;
	s = ( char *)src;

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return dest;
}
