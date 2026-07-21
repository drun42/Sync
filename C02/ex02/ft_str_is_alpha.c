/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:07:51 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/20 11:08:21 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
				return (0);
		}
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char *str = "";
	printf("%d", ft_str_is_alpha(str));

	char *str2 = "pizda";
        printf("%d", ft_str_is_alpha(str2));

        char *str3 = "PIZDQ";
        printf("%d", ft_str_is_alpha(str3));

        char *str4 = " ";
        printf("%d", ft_str_is_alpha(str4));

        char *str5 = "15";
        printf("%d", ft_str_is_alpha(str5));

        char *str6 = "pizda228";
        printf("%d", ft_str_is_alpha(str6));


}
*/
