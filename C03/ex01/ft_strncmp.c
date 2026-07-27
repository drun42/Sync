/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:37:12 by dshofer           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/27 01:05:26 by us               ###   ########.fr       */
=======
/*   Updated: 2026/07/27 00:23:10 by dshofer          ###   ########.fr       */
>>>>>>> d8651934a77356e02cf9fd58658e6f36b4bb7117
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
<<<<<<< HEAD
	while (i != n && s1[i] && s2[i])
=======
	while (i != n && s1[i]i && s)
>>>>>>> d8651934a77356e02cf9fd58658e6f36b4bb7117
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else
			i++;
	}
	if (i < n && (s1[i] != '\0' || s2[i] != '\0'))
		return (s1[i] - s2[i]);
	return (0);
}
/*
int	main(void)
{
	char str1[] = "ABCD";
	char str2[] = "ABC";	
	printf("%d\n", ft_strncmp(str1, str2, 10));
	
	char str3[] = "ABC";
        char str4[] = "ABCD";
        printf("%d\n", ft_strncmp(str3, str4, 10));

	char str5[] = "ABCD";
        char str6[] = "ABC";
        printf("%d\n", ft_strncmp(str5, str6, 3));

	char str7[] = "ABC";
        char str8[] = "ABCD";
        printf("%d\n", ft_strncmp(str7, str8, 3));

	char str9[] = "";
        char str10[] = "ABCD";
        printf("%d\n", ft_strncmp(str9, str10, 3));

	char str11[] = "ABC";
        char str12[] = "";
        printf("%d\n", ft_strncmp(str11, str12, 3));
}
*/
