/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:07:51 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/19 13:17:05 by dshofer          ###   ########.fr       */
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
			return (0);
			if (str[i] >= 'A' && str[i] <= 'Z')
				return (0);
		}
		i++;
	}
	return (1);
}
/*
int main(void)
{
	char *str = "pizda228";
	printf("%d", ft_str_is_alpha(str));
//	char *str = "pizda22";
	//ft_str_is_alpha(str);
}
*/
