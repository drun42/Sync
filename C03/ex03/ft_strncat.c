/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:43:25 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/20 10:28:24 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	unsigned int j;

	i = 0;
	j = 0;
	 while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		while (j < nb)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		break;
	}
	dest[i] = '\0';
	return(dest);
}
/*
int	main(void)
{
	char dest[225] = "pizda ";
	char src[] = "dyryavaya";
	unsigned int nb;

	nb = 3;	
	printf("%s\n",ft_strncat(dest, src, 3));
	printf("%s\n",ft_strncat(dest, src, 9));
	printf("%s\n",ft_strncat(dest, src, 35));
	printf("%s\n",ft_strncat(dest, src, 0));

}
*/
