/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:33:12 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/21 15:21:57 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = (char *)dest;
	s = (char *)src;

	if (n == 0)
	{
		return (d);
	}
	if (d == 0 && s == 0)
	{
		return (d);
	}
	else
	{
		if (d > s)
		{
			i = n - 1;
			while (i != 0)
			{
				d[i] = s[i];
				i--;
			}
			if (n != 0)
			d[0] = s[0];
			
		}
		else
		{
			i = 0;
			while (i < n)
			{
				d[i] = s[i];
				i++;
			}	
		}
		return (dest);
	}
}
