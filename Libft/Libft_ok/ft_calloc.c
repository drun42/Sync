/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*c;
	size_t	i;

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	c = (char *)p;
	i = 0;
	while (i < nmemb * size)
	{
		c[i] = 0;
		i++;
	}
	return (p);
}
