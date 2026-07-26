/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:37:12 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/26 04:22:13 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i != n && s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
			break ;
		}
		else
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[] = "ABCDE";
	char str2[] = "ABCDE";	
	printf("%d", ft_strncmp(str1, str2, 10));
}
*/
