/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/24 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	long	nb;

	nb = n;
	len = num_len(n);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		p[0] = '0';
	while (nb > 0)
	{
		len--;
		p[len] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (p);
}
