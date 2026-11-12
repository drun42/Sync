/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:21:27 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/12 23:54:33 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <string.h>

char	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;
	char	c;

	c = 0;
	i = 0;
	a = (char *)s;
	while (i < n)
	{
		a[i] = (unsigned char) c;
		i++;
	}
}
