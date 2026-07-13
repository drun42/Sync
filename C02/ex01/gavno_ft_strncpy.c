/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:14:32 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/13 17:49:02 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *src)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (src[i] != '\0')
	{
		count++;
		i++;
	}
	count ++;
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	if (len < n)
	{
		i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		n -= i;
		while (len > 0)
		{
			dest[i] = '\0';
			i++;
			len--;
		}
	}
	if (len > n)
	{
		i = 0;
		while (src[i] != n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

/*
int main(void)
{
	char src[] = "pizda";
	char dest[10];
	unsigned int n = 10;
	printf("%s", ft_strncpy(dest, src, n)); 
		
}
*/
