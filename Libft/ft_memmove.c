/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:33:12 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/14 17:15:56 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			tmp[n];
	char			*d;
	const char		*s;
	size_t			i;
	
	if (d > s)
	{
		i = n;
		d = (char *)dest;
		s = (char *)src;
	
		while (i != 0)
		{
			d[i] = s[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			d[i] = tmp[i];
			i++;
		}
		return (dest);
	}
	else 
		return 0;
